//
// Created by troy on 12/30/16.
//


#pragma once

#ifndef AIR_HOCKEY_PHYSICS_ENGINE_H
#define AIR_HOCKEY_PHYSICS_ENGINE_H

namespace task_physics_engine {
    void main(void *arg);

	enum direction_vector{ X, Y, AXIS_COUNT };
	
	static double default_puck_radius = 0;
	static double default_puck_mass = 0;
	
	static double default_table_length = 0;
	static double default_table_width = 0;
	
	static double default_hockey_stick_radius = 0;
	static double default_hockey_stick_mass = 0;

class Puck{
private:
	void check_collision();
protected:

public:
	double radius;
	double position[AXIS_COUNT];
	double velocity[AXIS_COUNT];
	double mass;

	Puck(double puck_radius = default_puck_radius, double puck_mass = default_puck_mass){};
	void dWorldStep();//更新物理状态
};

Puck::Puck(double puck_radius, double puck_mass)
{
	radius = puck_radius;
	mass = puck_mass;
}

void Puck::check_collision()
{

}

void Puck::dWorldStep()
{

}

class Table{
private:

protected:

public:
	double length;
	double width;
	Table(double table_length = default_table_length, double table_width = default_table_width){};
};

Table::Table(double table_length, double table_width)
{
	length = table_length;
	width = table_width;
}

class Hockey_stick{
private:
	void stick_checkstep(){};
protected:

public:
	double radius;
	double mass;
	double position[AXIS_COUNT];
	double velocity[AXIS_COUNT];
	Hockey_stick(double hockey_stick_radius = default_hockey_stick_radius, double hockey_stick_mass = default_hockey_stick_mass){};
};

Hockey_stick::Hockey_stick(double hockey_stick_radius, double hockey_stick_mass)
{
	radius = default_hockey_stick_radius;
	mass = default_hockey_stick_mass;
}

void Hockey_stick::stick_checkstep()
{

}
}

#endif //AIR_HOCKEY_PHYSICS_ENGINE_H
