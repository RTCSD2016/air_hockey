//
// Created by troy on 12/30/16.
//


#pragma once

#ifndef AIR_HOCKEY_TESTUNITTEST_H
#define AIR_HOCKEY_TESTUNITTEST_H

#include <cppunit/extensions/HelperMacros.h>

class TestUnitTest: public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestUnitTest);
        CPPUNIT_TEST(test_success);
        CPPUNIT_TEST(test_fail);
        CPPUNIT_TEST(test_double_success);
        CPPUNIT_TEST(test_double_fail);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_success();
    void test_fail();
    void test_double_success();
    void test_double_fail();
};


#endif //AIR_HOCKEY_TESTUNITTEST_H
