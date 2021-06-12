#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluate) {
    Rand* test = new Rand();
    EXPECT_GE(test->stringify(), "");
    EXPECT_GE(test->evaluate(), 0);
}

#endif //__OP_TEST_HPP__
