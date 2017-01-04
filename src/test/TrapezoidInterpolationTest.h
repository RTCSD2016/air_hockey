//
// Created by troy on 1/3/17.
//


#pragma once

#ifndef SIMPLE_MOTION_TRAPEZOIDINTERPOLATIONTEST_H
#define SIMPLE_MOTION_TRAPEZOIDINTERPOLATIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class TrapezoidInterpolationTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(TrapezoidInterpolationTest);
        CPPUNIT_TEST(base_function);
    CPPUNIT_TEST_SUITE_END();

public:
    void base_function();
};

#endif //SIMPLE_MOTION_TRAPEZOIDINTERPOLATIONTEST_H
