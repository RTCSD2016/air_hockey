//
// Created by 张启宁 on 12/29/16.
//

#include "interpolation.h"

#include <stdexcept>

Interpolation::Interpolation() {
    this->status = kIntNotYetConfigured;
    this->type = "unkown";
}

Interpolation::~Interpolation() {}

std::string Interpolation::get_type() {
    return this->type;
}

InterpolationState Interpolation::get_status() {
    return this->status;
}

double Interpolation::get_position(void) {
    return this->position;
}

double Interpolation::get_velocity(void) {
    return this->velocity;
}

double Interpolation::get_acceleration(void) {
    return this->acceleration;
}

double Interpolation::get_jerk(void) {
    return this->jerk;
}

void InterpolationConfigure::set_time(double time) {
    this->target_time = time;
}

void InterpolationConfigure::set_position(double position) {
    this->target_position = position;
}

void InterpolationConfigure::set_velocity(double velocity) {
    this->target_velocity = velocity;
}

void InterpolationConfigure::set_acceleration(double acceleration) {
    this->max_acceleration = acceleration;
}

void InterpolationConfigure::set_jerk(double jerk) {
    this->max_jerk = jerk;
}
