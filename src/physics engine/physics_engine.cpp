#include "physics_engine.h"

#include <stdexcept>

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
