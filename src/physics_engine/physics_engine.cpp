//
// Created by troy on 12/30/16.
//

#include "physics_engine.h"

#include <native/task.h>

#include <rtdk.h>
#include "common.h"

namespace task_physics_engine {
	RTIME pre_time,cur_time;//ns
	double step_time;//秒

	Puck ice_puck = Puck();
	Table ice_table = Table();
	Hockey_stick stick = Hockey_stick();

	Puck::Puck(double puck_radius = default_puck_radius, double puck_mass = default_puck_mass){
		radius = puck_radius;
		mass = puck_mass;

		cur_position[X] = 50;
		cur_position[Y] = 100;

		velocity[X] = 0;
		velocity[Y] = 0;
	};

	void Puck::check_collision(){
		if (cur_position[X] <= 5 || cur_position[X] >= 95)
		{
			goal_flag = ungoal;
			velocity[X] = -velocity[X];
		}

		if (cur_position[Y] <= 5 || cur_position[Y] >= 195)
		{
			if (cur_position[X] < 65 && cur_position[X] > 35)
			{
				if (cur_position[Y] <= 5) goal_flag = lose;
				if (cur_position[Y] >= 195) goal_flag = win;

				velocity[X] = 0;
				velocity[Y] = 0;
			}
			else { velocity[Y] = -velocity[Y]; goal_flag = ungoal }
		}

		if ((cur_position[X] - axis_x.position) * (cur_position[X] - axis_x.position) + (cur_position[Y] - axis_y.position) * (cur_position[Y] - axis_y.position) <= 225)
		{
			double slope;
			double speed_temp;

			slope = (cur_position[Y] - axis_y.position) / (1.0 * (cur_position[X] - axis_x.position));

			speed_temp = velocity[Y];
			velocity[Y] = axis_y.velocity + (velocity[X] - 2 * axis_x.velocity) * slope;
			velocity[X] = axis_x.velocity + (speed_temp - 2 * axis_y.velocity) / slope;
		}
	};

	void Puck::update_position(){
		if (goal_flag != ungoal)
		{
			cur_position[X] = 50;
			cur_position[Y] = 100;
		}

		if (collision_flag == un_col)
		{
			cur_position[X] = cur_position[X] + step_time*velocity[X];
			cur_position[Y] = cur_position[Y] + step_time*velocity[Y];
		}
		if (collision_flag != un_col)
		{
			cur_position[X] = cur_position[X] + step_time*velocity[X]/2;
			cur_position[Y] = cur_position[Y] + step_time*velocity[Y]/2;//假设是在1/2时间碰撞
		}
	};

	void Puck::update_velocity(){
		//ball_x.velocity = velocity[X];
		//ball_y.velocity = velocity[Y];
	};

	void Puck::PuckStep(){
		check_collision();
		update_velocity();
		update_position();

		ball_x.position = cur_position[X];
		ball_y.position = cur_position[Y];

		ball_x.velocity = velocity[X];
		ball_y.velocity = velocity[Y];
	};

	Table::Table(double table_length = default_table_length, double table_width = default_table_width, double goal_length = default_goal_length)
	{
		length = table_length;
		width = table_width;
		goalline = goal_length;
	}

	Hockey_stick::Hockey_stick(double hockey_stick_radius = default_hockey_stick_radius, double hockey_stick_mass = default_hockey_stick_mass){
	
		radius = hockey_stick_radius;
		mass = hockey_stick_mass;

		//cur_position[X] = 50;
		//cur_position[Y] = 0;

		//velocity[X] = 0;
		//velocity[Y] = 0;
	};

	void Hockey_stick::stick_checkstep(){
		pre_position[X] = cur_position[X];
		pre_position[Y] = cur_position[Y];

		cur_position[X] = axis_x.position;
		cur_position[Y] = axis_y.position;

		velocity[X] = axis_x.velocity;
		velocity[Y] = axis_y.velocity;

		if (cur_position[X] <= 0) cur_position[X] = 0;
		if (cur_position[X] >= 100) cur_position[X] = 100;
		if (cur_position[Y] <= 0) cur_position[Y] = 0;
		if (cur_position[Y] >= 200) cur_position[Y] = 200;
	};

	double get_step_time(){
		pre_time = cur_time;
		cur_time = rt_timer_read();

		return double((cur_time - pre_time)/1000000);
	};

    void main(void *arg) {
        rt_printf("[physics_engine] hello\n");

        unsigned long mask;

		goal_flag = ungoal;
		collision_flag = un_col;
		pre_time = rt_timer_read();

        while (1) {
            rt_event_wait(&event,
                          event_mask::kTerminate,
                          &mask,
                          EV_ANY,
                          5000000000);
            if (mask & event_mask::kTerminate)
                goto PHYSICS_ENGINE_TERMINATE;
 //           rt_printf("[physics_engine] I'm waiting for codes...\n");

			step_time=get_step_time();
			stick.stick_checkstep();
			ice_puck.PuckStep();
        }

        PHYSICS_ENGINE_TERMINATE:
        rt_printf("[physics_engine] exit\n");
    }
	}