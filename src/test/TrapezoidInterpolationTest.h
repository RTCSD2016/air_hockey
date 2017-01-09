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
        CPPUNIT_TEST(test_1);
        CPPUNIT_TEST(test_2);
        CPPUNIT_TEST(test_3);
        CPPUNIT_TEST(test_4);
    CPPUNIT_TEST_SUITE_END();

public:
    void base_function();

    void test_1();

    void test_2();

    void test_3();

    void test_4();
};

#endif //SIMPLE_MOTION_TRAPEZOIDINTERPOLATIONTEST_H
