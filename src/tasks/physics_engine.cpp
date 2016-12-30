//
// Created by troy on 12/30/16.
//

#include "physics_engine.h"

#include <native/task.h>

#include <rtdk.h>
#include "common.h"

namespace task_physics_engine {
    void main(void *arg) {
        rt_printf("[physics_engine] hello\n");

        unsigned long mask;

        while (1) {
            rt_event_wait(&event,
                          event_mask::kTerminate,
                          &mask,
                          EV_ANY,
                          5000000000);
            if (mask & event_mask::kTerminate)
                goto PHYSICS_ENGINE_TERMINATE;
            rt_printf("[physics_engine] I'm waiting for codes...\n");
        }

        PHYSICS_ENGINE_TERMINATE:
        rt_printf("[physics_engine] exit\n");
    }
}