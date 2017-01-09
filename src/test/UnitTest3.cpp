#include "TrapezoidInterpolationTest.h"
#include "interpolation/trapezoid_interpolation.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TrapezoidInterpolationTest);                      // 注册到全局测试集
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TrapezoidInterpolationTest, "trapezoid");

/**
 * @brief 测试：判断在正向运动目标速度反向过程中某一时刻的速度和位移是否正确
 */
void TrapezoidInterpolationTest::base_function() {
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
	
    algorithm.move(12);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(290, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, algorithm.get_velocity(), 0.1);//判断正向减速过程中某一时刻的速度和位移是否正确
    
    algorithm.move(18);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(290, algorithm.get_position(), 0.1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-10, algorithm.get_velocity(), 0.1);//判断反向加速过程中某一时刻的速度和位移是否正确
