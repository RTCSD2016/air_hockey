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
    
    Puck::Puck(double puck_radius, double puck_mass)
    {
        radius = puck_radius;
        mass = puck_mass;
    }
    
    Table::Table(double table_length, double table_width, double goal_length1, double goal_length2)
    {
        length = table_length;
        width = table_width;
        goalline1 = goal_length1;
        goalline2 = goal_length2;
    }
    
    Hockey_stick::Hockey_stick(double hockey_stick_radius, double hockey_stick_mass)
    {
        radius = default_hockey_stick_radius;
        mass = default_hockey_stick_mass;
    }
}
