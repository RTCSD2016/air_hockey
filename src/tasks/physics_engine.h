//
// Created by troy on 12/30/16.
//


#pragma once

#ifndef AIR_HOCKEY_PHYSICS_ENGINE_H
#define AIR_HOCKEY_PHYSICS_ENGINE_H

namespace task_physics_engine {
    void main(void *arg);

	enum direction_vector{ X, Y, AXIS_COUNT };
	enum flag1{ ungoal, win,lose }goal_flag;//进球标志
	enum flag2{ table_col, stick_col }collision_flag;//碰撞标志

	static double default_puck_radius = 0;
	static double default_puck_mass = 0;

	static double default_table_length = 0;
	static double default_table_width = 0;

	static double default_hockey_stick_radius = 0;
	static double default_hockey_stick_mass = 0;
	
	static double default_goal_length1 = 0;
	static double default_goal_length2 = 0;
	
class Puck{
private:
	double collision_time;
	double collision_position[AXIS_COUNT];

	void check_collision();//检查碰撞
	void update_position();//更新位置
	void update_velocity();//更新速度

protected:

public:
	double radius;
	double mass;
	double pre_position[AXIS_COUNT], cur_position[AXIS_COUNT];//上一步和现在的位置
	double velocity[AXIS_COUNT];
	double mass;

	void dWorldStep();//更新物理状态
	Puck(double r = default_puck_radius, double m = default_puck_mass);
};

class Table{
private:

protected:

public:
	double length;
	double width;
	double goalline1;
	double goalline2;

	Table(double table_length = default_table_length, double table_width = default_table_width, double goal_length1 = default_goal_length1, double goal_length2 = default_goal_length2){};
};

class Hockey_stick{
private:
	void stick_checkstep(){};
protected:
	
public:
	double radius;
	double mass;
	double pre_position[AXIS_COUNT], cur_position[AXIS_COUNT];
	double velocity[AXIS_COUNT];

	Hockey_stick(double hockey_stick_radius = default_hockey_stick_radius, double hockey_stick_mass = default_hockey_stick_mass){};				
};
}

#endif //AIR_HOCKEY_PHYSICS_ENGINE_H
