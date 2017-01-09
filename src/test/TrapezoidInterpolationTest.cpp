//
// Created by troy on 1/4/17.
//

#include "TrapezoidInterpolationTest.h"
#include "interpolation/trapezoid_interpolation.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TrapezoidInterpolationTest);                      // 注册到全局测试集
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TrapezoidInterpolationTest, "trapezoid");

/**
 * @brief 测试：判断能否在指定时间运动到指定位置，加速度足够大。
 */
void TrapezoidInterpolationTest::base_function() {
    TrapezoidInterpolation algorithm;
    algorithm.set_time(25);
    algorithm.set_position(300);
    algorithm.set_velocity(0);
    algorithm.set_acceleration(20);

    algorithm.start(0, 0, 0);

    algorithm.move(25);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(300, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, algorithm.get_velocity(), 0.1);
}

/**
 * @brief 测试：判断在正向运动过程中某一时刻的速度和位移是否正确
 */
void TrapezoidInterpolationTest::test_1() {
    TrapezoidInterpolation algorithm;
    algorithm.set_time(10);
    algorithm.set_position(150);
    algorithm.set_velocity(10);
    algorithm.set_acceleration(5);

    algorithm.start(0, 0, 0);

    algorithm.move(2);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_velocity(), 0.1);//判断加速过程中某一时刻的速度和位移是否正确

    algorithm.move(6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(80, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(20, algorithm.get_velocity(), 0.1);//判断匀速过程中某一时刻的速度和位移是否正确

    algorithm.move(9);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(137.5, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(15, algorithm.get_velocity(), 0.1);//判断减速过程中某一时刻的速度和位移是否正确
}

/**
 * @brief 测试：判断在反向运动过程中某一时刻的速度和位移是否正确
 */
void TrapezoidInterpolationTest::test_2() {
    TrapezoidInterpolation algorithm;
    algorithm.set_time(10);
    algorithm.set_position(-150);
    algorithm.set_velocity(-10);
    algorithm.set_acceleration(5);

    algorithm.start(0, 0, 0);

    algorithm.move(2);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_velocity(), 0.1);//判断加速过程中某一时刻的速度和位移是否正确

    algorithm.move(6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-80, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-20, algorithm.get_velocity(), 0.1);//判断匀速过程中某一时刻的速度和位移是否正确

    algorithm.move(9);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-137.5, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-15, algorithm.get_velocity(), 0.1);//判断减速过程中某一时刻的速度和位移是否正确
}

/**
 * @brief 测试：判断在正向运动目标速度反向过程中某一时刻的速度和位移是否正确
 */
void TrapezoidInterpolationTest::test_3() {
    TrapezoidInterpolation algorithm;
    algorithm.set_time(19);
    algorithm.set_position(277.5);
    algorithm.set_velocity(-15);
    algorithm.set_acceleration(5);

    algorithm.start(0, 0, 0);

    algorithm.move(2);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_velocity(), 0.1);//判断加速过程中某一时刻的速度和位移是否正确

    algorithm.move(8);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(150, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(30, algorithm.get_velocity(), 0.1);//判断匀速过程中某一时刻的速度和位移是否正确

    algorithm.move(14);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(290, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_velocity(), 0.1);//判断正向减速过程中某一时刻的速度和位移是否正确

    algorithm.move(18);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(290, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_velocity(), 0.1);//判断反向加速过程中某一时刻的速度和位移是否正确
}

/**
 * @brief 测试：判断在反向运动（目标位移反向）目标速度正向过程中某一时刻的速度和位移是否正确
 */
void TrapezoidInterpolationTest::test_4() {
    TrapezoidInterpolation algorithm;
    algorithm.set_time(19);
    algorithm.set_position(-277.5);
    algorithm.set_velocity(15);
    algorithm.set_acceleration(5);

    algorithm.start(0, 0, 0);

    algorithm.move(2);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_velocity(), 0.1);//判断反向加速过程中某一时刻的速度和位移是否正确

    algorithm.move(8);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-150, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-30, algorithm.get_velocity(), 0.1);//判断反向匀速过程中某一时刻的速度和位移是否正确

    algorithm.move(14);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-290, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_velocity(), 0.1);//判断反向减速过程中某一时刻的速度和位移是否正确

    algorithm.move(18);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(290, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_velocity(), 0.1);//判断正向加速过程中某一时刻的速度和位移是否正确
}
