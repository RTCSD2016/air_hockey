//
// Created by troy on 12/29/16.
//

#include "trapezoid_interpolation.h"

#include <stdexcept>

TrapezoidInterpolation::TrapezoidInterpolation() {
    this->type = "trapezoid interpolation";
}

InterpolationState TrapezoidInterpolation::start(const TimeInS now, const double start_position,
                                                 const double start_velocity) {
    throw new std::logic_error("not implemented");
}

InterpolationState TrapezoidInterpolation::move(const TimeInS now) {
    throw new std::logic_error("not implemented");
}

TrapezoidInterpolation::~TrapezoidInterpolation() {
}
