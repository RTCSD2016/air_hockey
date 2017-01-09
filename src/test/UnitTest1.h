#include "TrapezoidInterpolationTest.h"
#include "interpolation/trapezoid_interpolation.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TrapezoidInterpolationTest);                      // 注册到全局测试集
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TrapezoidInterpolationTest, "trapezoid");

/**
 * @brief 测试：判断在正向运动过程中某一时刻的速度和位移是否正确
 */
void TrapezoidInterpolationTest::base_function() {
    TrapezoidInterpolation algorithm;
    algorithm.set_time(10);
    algorithm.set_position(120);
    algorithm.set_velocity(10);
    algorithm.set_acceleration(5);

    algorithm.start(0, 0, 0);

    algorithm.move(2);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_velocity(), 0.1);//判断加速过程中某一时刻的速度和位移是否正确

    algorithm.move(6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(50, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(20, algorithm.get_velocity(), 0.1);//判断匀速过程中某一时刻的速度和位移是否正确
	
	algorithm.move(9);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(107.5, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(15, algorithm.get_velocity(), 0.1);//判断减速过程中某一时刻的速度和位移是否正确
