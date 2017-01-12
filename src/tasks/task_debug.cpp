//
// Created by troy on 1/12/17.
//

#include "task_debug.h"

#include "common.h"

#include <rtdk.h>
#include <native/timer.h>
#include <native/event.h>

namespace task_debug {
    void main(void *arg) {
        UNUSED(arg);
        unsigned long mask;
        rt_printf("[debug] hello\n");
        rt_printf("[debug] Print current location and speed\n[debug] Format: Time Position(x,y) Velocity(x,y)\n");

        double t0 = rt_timer_read() / 1e9;

        while (1) {
            rt_printf("[debug] %0.3f\t(%0.3f, %0.3f)\t(%0.3f, %0.3f)\n",
                      (rt_timer_read() / 1e9 - t0),
                      axis_x.position, axis_y.position,
                      axis_x.velocity, axis_y.velocity);
            rt_event_wait(&event,
                          event_mask::kTerminate,
                          &mask,
                          EV_ANY,
                          1000000000);
            if (mask & event_mask::kTerminate)
                goto DEBUG_TERMINATE;
        }
        DEBUG_TERMINATE:
        rt_printf("[debug] exit\n");
    }
}