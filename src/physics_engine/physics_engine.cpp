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

        velocity[X] = 0;
        velocity[Y] = 0;
    }
    
    void Puck::check_collision()
    {
        if(cur_position[X] <= 5 || cur_position[X] >= 95) velocity[X] = -velocity[X];
        if(cur_position[Y] <= 5 || cur_position[Y] >= 195)
        {
            if(cur_position[X] < 65 && cur_position[X] > 35)
            {
                if(cur_position[Y] <= 5) goal_flag = 1;
                if(cur_position[Y] >= 195) goal_flag = 2;

                velocity[X] = 0;
                velocity[Y] = 0;
            } else {velocity[Y] = -velocity[Y];}
        }
        
        if((cur_position[X] - ball_x.position) * (cur_position[X] - ball_x.position) + (cur_position[Y] - ball_y.position) * (cur_position[Y] - ball_y.position) <= 225)
    }
    
    void Puck::update_position()
    {
        if(goal_flag > 0)
        {
            cur_position[X] = 50;
            cur_position[Y] = 100;
        }
    }
    
    void Puck::update_velocity()
    {
        ball_x.velocity = velocity[X];
        ball_y.velocity = velocity[Y];
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
}
