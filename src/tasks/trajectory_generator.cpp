//
// Created by troy on 12/10/16.
//

#include "trajectory_generator.h"

#include <stdexcept>
#include <common.h>

#include <rtdk.h>
#include <native/task.h>
#include <native/timer.h>
#include <native/queue.h>

#include "interpolation/interpolation.h"


namespace task_trajectory_generator {
    void main(void *arg) {
        auto axis = (AxisStatus *) arg;
        rt_printf("[traj_%s] hello\n", axis->name);

        rt_task_set_periodic(NULL, TM_NOW, 1000000);

        enum TaskState {
            kTaskIdle, kTaskRunning, kTaskEnd, kTaskError
        };

        TaskState state = kTaskIdle;
        Interpolation *interpolation = nullptr;

        RT_QUEUE queue_command;
        if (rt_queue_bind(&queue_command, axis->name, TM_NONBLOCK)) {
            rt_printf("[traj_%s] queue not found\n", axis->name);
            goto TRAJECTORY_GENERATED_TERMINATED;
        } else {
            rt_printf("[traj_%s] queue bind\n", axis->name);
        }

        unsigned long mask;
        while (1) {
            rt_task_wait_period(NULL);
            auto now = rt_timer_read();

            rt_event_wait(&event,
                          event_mask::kTerminate,
                          &mask,
                          EV_ANY,
                          TM_NONBLOCK);
            if (mask & event_mask::kTerminate)
                goto TRAJECTORY_GENERATED_TERMINATED;

            switch (state) {
                case kTaskIdle:
                    rt_event_wait(&event,
                                  event_mask::kRequest | event_mask::kTerminate,
                                  &mask,
                                  EV_ANY,
                                  TM_INFINITE);
                    if (mask & event_mask::kTerminate)
                        goto TRAJECTORY_GENERATED_TERMINATED;

                    void *msg;
                    rt_queue_receive(&queue_command, &msg, TM_INFINITE);
                    memcpy(&interpolation, msg, sizeof(Interpolation *));
                    rt_queue_free(&queue_command, msg);

                    rt_printf("[traj_%s] receive command\n", axis->name);

                    if (interpolation->start(rt_timer_read() / 1e9,
                                             axis->position,
                                             axis->velocity) == kIntIdle)
                        state = kTaskRunning;
                    else {
                        state = kTaskError;
                        rt_printf("[traj_%s] Error Occurred\n", axis->name);
                        break;
                    }
                case kTaskRunning: {
                    auto ret = interpolation->move(now / 1e9);
                    axis->position = interpolation->get_position();
                    axis->velocity = interpolation->get_velocity();
                    switch (ret) {
                        case kIntError:
                            state = kTaskError;
                            rt_printf("[traj_%s] Error Occurred\n", axis->name);
                            break;
                        case kIntRunning:
                            break;
                        case kIntDone:
                            state = kTaskEnd;
                            break;
                        default:
                            state = kTaskError;
                            rt_printf("[traj_%s] unknown state\n", axis->name);
                            break;
                    }
                }
                    break;
                case kTaskEnd:
                    state = kTaskIdle;
                    delete (interpolation);
                    interpolation = nullptr;
                    rt_event_signal(&event,
                                    event_mask::kDone);
                    break;
                case kTaskError:
                    break;
            }
        }

        TRAJECTORY_GENERATED_TERMINATED:
        rt_printf("[traj_%s] exit\n", axis->name);
        if (interpolation)
            delete (interpolation);
    }
}
