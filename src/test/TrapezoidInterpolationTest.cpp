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
