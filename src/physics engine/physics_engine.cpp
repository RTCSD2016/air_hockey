#include "physics_engine.h"
#include <stdexcept>
#include <native/task.h>
#include <rtdk.h>
#include "common.h"

namespace task_physics_engine {
    Puck::Puck(double puck_radius, double puck_mass)
    {
        radius = puck_radius;
        mass = puck_mass;
        
        cur_position[X] = 50;
        cur_position[Y] = 100;

        velocity[X] = 10;
        velocity[Y] = 0;
    }

    Table::Table(double table_length, double table_width, double goal_length)
    {
        length = table_length;
        width = table_width;
        goalline = goal_length;
    }

    Hockey_stick::Hockey_stick(double hockey_stick_radius)
    {
        radius = default_hockey_stick_radius;
        
        cur_position[X] = 50;
        cur_position[Y] = 0;

        velocity[X] = 0;
        velocity[Y] = 0;
    }

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
