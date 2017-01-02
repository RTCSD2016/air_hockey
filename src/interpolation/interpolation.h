//
// Created by 张启宁 on 12/12/16.
//

#pragma once

#ifndef SIMPLE_MOTION_INTERPOLATION_H
#define SIMPLE_MOTION_INTERPOLATION_H

#include <string>

typedef double TimeInS;

/**
 * Interpolation state
 */
enum InterpolationState {
    kIntNotYetConfigured,
    kIntIdle,
    kIntRunning,
    kIntDone,
    kIntError,
};

class Interpolation {
private:
    InterpolationState status;

protected:
    std::string type;
    double position;
    double velocity;
    double acceleration;
    double jerk;

//    double p;//added by 周佩 on 2017/1/2.
//    double v;
//    double a;
//    double j;

    /**
     * @brief Not allow create instance directly
     */
    Interpolation();

public:
    virtual ~Interpolation();

    /**
     * @brief initialize the interpolation alogrithm (pure virtual function)
     * @param start_position start position
     * @param start_velocity start velocity
     * @return current interpolating status, only kError/kRunning
     */
    virtual InterpolationState start(const TimeInS now,
                                     const double start_position,
                                     const double start_velocity) = 0;

    /**
     * @brief interpolate once (pure virtual function)
     * @param TimeInS current time stamp
     * @return current interpolating status
     */
    virtual InterpolationState move(const TimeInS now) = 0;

    /**
     * @brief return current interpolating status
     * @return interpolating status
     */
    virtual InterpolationState get_status(void);

    /**
     * @brief return the type of this interpolation
     * @return the type of this interpolation
     */
    std::string get_type(void);

    /**
     * @brief return the position
     * @return the position
     */
    double get_position(void);

    /**
     * @brief return the velocity
     * @return the velocity
     */
    double get_velocity(void);

    /**
     * @brief return the acceleration
     * @return the acceleration
     */
    double get_acceleration(void);

    /**
     * @brief return the jerk
     * @return the jerk
     */
    double get_jerk(void);
};

class InterpolationConfigure {
protected:
    double target_time;
    double target_position;
    double target_velocity;
    double max_acceleration;
    double max_jerk;

public:
    void set_time(double time);
    void set_position(double position);
    void set_velocity(double velocity);
    void set_acceleration(double acceleration);
    void set_jerk(double jerk);
};

#endif //SIMPLE_MOTION_INTERPOLATION_H
