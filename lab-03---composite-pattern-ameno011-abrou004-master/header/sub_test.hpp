#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"

TEST(SubTest, OpEvaluateNonZero)
{
	Base* x = new Op(5.0);
	Base* y = new Op(3.0);
	Base* test = new Sub (x,y);
	EXPECT_EQ(test -> evaluate(), 2.0);
}

#endif //__SUB_TEST_HPP__
