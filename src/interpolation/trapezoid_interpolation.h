//
// Created by troy on 12/29/16.
//


#pragma once

#ifndef AIR_HOCKEY_TRAPEZOIDINTERPOLATION_H
#define AIR_HOCKEY_TRAPEZOIDINTERPOLATION_H

#include <interpolation.h>

class TrapezoidInterpolation final : public Interpolation,
                                     public InterpolationConfigure {
public:
    TrapezoidInterpolation();

    virtual ~TrapezoidInterpolation();

    virtual InterpolationState start(const TimeInS now,
                                     const double start_position,
                                     const double start_velocity);

    virtual InterpolationState move(const TimeInS now);
};


#endif //AIR_HOCKEY_TRAPEZOIDINTERPOLATION_H
