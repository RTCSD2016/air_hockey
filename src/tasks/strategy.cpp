//
// Created by troy on 12/30/16.
//

#include "strategy.h"

#include <native/task.h>
#include <native/queue.h>
#include <native/event.h>

#include "common.h"
#include <interpolation/interpolation.h>
#include <interpolation/trapezoid_interpolation.h>
#include <rtdk.h>

namespace task_strategy {
    int send_command_trapezoid(RT_QUEUE &queue,
                               const double time,
                               const double position,
                               const double velocity,
                               const double acceleration) {

        auto new_cmd = (TrapezoidInterpolation **) rt_queue_alloc(&queue, sizeof(InterpolationConfigure *));
        *new_cmd = new TrapezoidInterpolation();
        (*new_cmd)->set_time(time);
        (*new_cmd)->set_position(position);
        (*new_cmd)->set_velocity(velocity);
        (*new_cmd)->set_acceleration(acceleration);
        return rt_queue_send(&queue,
                             new_cmd,
                             sizeof(Interpolation *),
                             Q_NORMAL);
    }

    void main(void *arg) {
        unsigned long mask;
        rt_printf("[strategy] hello\n");

        while (1) {
            rt_event_wait(&event,
                          event_mask::kTerminate,
                          &mask,
                          EV_ANY,
                          5000000000);
            if (mask & event_mask::kTerminate)
                goto STRATEGY_TERMINATE;
            rt_printf("[strategy] I'm waiting for codes...\n");
        }

        STRATEGY_TERMINATE:
        rt_printf("[strategy] exit\n");
    }
}