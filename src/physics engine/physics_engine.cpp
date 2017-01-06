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
    
    void Puck::check_collision()
    {
        if(cur_position[X] <= 5 || cur_position[X] >= 95) velocity[X] = -velocity[X];
        if(cur_position[Y] <= 5 || cur_position[Y] >= 195) velocity[Y] = -velocity[Y];//撞桌子
        
        if((cur_position[X] - ) * (cur_position[X] - ) + (cur_position[Y] - ) * (cur_position[Y] - ) <= 225)
    }
    
    void Puck::update_position()
    {
    
    }
    
    void Puck::update_velocity()
    {
    
    }

    Table::Table(double table_length, double table_width, double goal_length)
    {
        length = table_length;
        width = table_width;
        goalline = goal_length;
    }

    Hockey_stick::Hockey_stick(double hockey_stick_radius, double hockey_stick_mass)
    {
        radius = hockey_stick_radius;
        mass = hockey_stick_mass;
        
        cur_position[X] = 50;
        cur_position[Y] = 0;

        velocity[X] = 0;
        velocity[Y] = 0;
    }
    
    void Hockey_stick::stick_check()
    {
        if(cur_position[X] <= 0) cur_position[X] = 0;
        if(cur_position[X] >= 100) cur_position[X] = 100;
        if(cur_position[Y] <= 0) cur_position[Y] = 0;
        if(cur_position[Y] >= 200) cur_position[Y] = 200;
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
