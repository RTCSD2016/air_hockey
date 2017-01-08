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
        if(cur_position[X] <= 5 || cur_position[X] >= 95) 
        {
            goal_flag = ungoal;
            velocity[X] = -velocity[X];
        }
        
        if(cur_position[Y] <= 5 || cur_position[Y] >= 195)
        {
            if(cur_position[X] < 65 && cur_position[X] > 35)
            {
                if(cur_position[Y] <= 5) goal_flag = lose;
                if(cur_position[Y] >= 195) goal_flag = win;

                velocity[X] = 0;
                velocity[Y] = 0;
            } else {velocity[Y] = -velocity[Y]; goal_flag = ungoal}
        }
        
        if((cur_position[X] - axis_x.position) * (cur_position[X] - axis_x.position) + (cur_position[Y] - axis_y.position) * (cur_position[Y] - axis_y.position) <= 225)
        {
            double slope;
            double speed_temp;
            
            slope = (cur_position[Y] - axis_y.position) / (1.0 * (cur_position[X] - axis_x.position));
            
            speed_temp = velocity[Y];
            velocity[Y] = axis_y.velocity + (velocity[X] - 2 * axis_x.velocity) * slope;
            velocity[X] = axis_x.velocity + (speed_temp - 2 * axis_y.velocity) / slope;
        }
    }
    
    void Puck::update_position(double step_time)
    {
        if(goal_flag != ungoal)
        {
            cur_position[X] = 50;
            cur_position[Y] = 100;
        }
        
        if (collision_flag == un_col)
        {
            cur_position[X] = cur_position[X] + step_time * velocity[X];
            cur_position[Y] = cur_position[Y] + step_time * velocity[Y];
        }
        
        if (collision_flag != un_col)
        {
            cur_position[X] = cur_position[X] + step_time * velocity[X] / 2;
            cur_position[Y] = cur_position[Y] + step_time * velocity[Y] / 2;
        }
        
        ball_x.position = cur_position[X];
		ball_y.position = cur_position[Y];
    }
    
    void Puck::update_velocity()
    {
        ball_x.velocity = velocity[X];
        ball_y.velocity = velocity[Y];
    }
    
    void Puck::dWorldStep(double step_time)
    {
        check_collision();
		update_velocity();
		update_position(step_time);
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
