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
        static double pre_time;
        static double cur_time;
        static double step_time;
        
        goal_flag = ungoal;
		collision_flag = un_col;
		cur_time = rt_timer_read();

        while (1) {
            rt_event_wait(&event,
                          event_mask::kTerminate,
                          &mask,
                          EV_ANY,
                          5000000000);
            if (mask & event_mask::kTerminate)
                goto PHYSICS_ENGINE_TERMINATE;
            rt_printf("[physics_engine] I'm waiting for codes...\n");
            
            pre_time = cur_time;
            cur_time = rt_timer_read();
            step_time = (cur_time - pre_time)/1000000.0;
        }

        PHYSICS_ENGINE_TERMINATE:
        rt_printf("[physics_engine] exit\n");
    }
}
