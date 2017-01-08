//
// Created by troy on 12/30/16.
//

#pragma once

#ifndef AIR_HOCKEY_PHYSICS_ENGINE_H
#define AIR_HOCKEY_PHYSICS_ENGINE_H

namespace physics_engine {
    enum direction_vector{ X, Y, AXIS_COUNT };
    enum flag1{ ungoal, win,lose } goal_flag;//进球标志
    enum flag2{ un_col, table_col, stick_col } collision_flag;//碰撞标志

    static double default_puck_radius = 5;//半径5mm	
    static double default_puck_mass = 1;//质量1kg
    
    static double default_table_length = 200;//球桌长200mm
    static double default_table_width = 100;//球桌宽100mm
    
    static double default_hockey_stick_radius = 10;//击球器半径10mm
    static double default_hockey_stick_mass = 5;//击球器质量5kg
    
    static double default_goal_length = 30;//球门长度30mm，位于短边中央

    class Puck{
    private:
        double collision_time;
        double collision_position[AXIS_COUNT];

        void check_collision();//检查碰撞
        void update_position(double step_time);//更新位置
        void update_velocity();//更新速度

    protected:

    public:
        double radius;
        double mass;
        double pre_position[AXIS_COUNT], cur_position[AXIS_COUNT];//上一步和现在的位置
        double velocity[AXIS_COUNT];
        double mass;
        void (*on_collide)(void) = nullptr;
        void (*on_game_over)(void) = nullptr;

        void dWorldStep(double step_time);//更新物理状态
        Puck(double r = default_puck_radius, double m = default_puck_mass);
        void new_ball(AxisStatus new_ball_x, AxisStatus new_ball_y);
    };

    class Table{
    private:

    protected:

    public:
        double length;
        double width;
        double goalline;

        Table(double table_length = default_table_length, double table_width = default_table_width, double goal_length = default_goal_length){};
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
        void stick_check();//击球器限位
    };
}

#endif //AIR_HOCKEY_PHYSICS_ENGINE_H