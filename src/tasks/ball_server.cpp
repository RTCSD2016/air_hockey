//
// Created by troy on 1/6/17.
//

#include "ball_server.h"

#include <random>

#include <native/timer.h>
#include <rtdk.h>

#include <common.h>

namespace task_ball_server {
    inline double random_range(double lowest, double highest) {
        return lowest + (highest - lowest) * random();
    }

    inline void serve_a_ball(void) {

    }

    void main(void *arg) {
        UNUSED(arg);
        rt_printf("[ball_server] hello\n");

        srand((unsigned int)rt_timer_read());

        unsigned long mask;
        while (1) {
            rt_event_clear(&event, event_mask::kGameOver | event_mask::kServe, nullptr);
            serve_a_ball();
            rt_event_signal(&event, event_mask::kServe);

            rt_event_wait(&event,
                          event_mask::kTerminate | event_mask::kGameOver,
                          &mask,
                          EV_ANY,
                          5000000000);
            if (mask & event_mask::kTerminate)
                goto BALL_SERVER_TERMINATE;
        }

        BALL_SERVER_TERMINATE:
        rt_printf("[ball_server] exit\n");
    }
}