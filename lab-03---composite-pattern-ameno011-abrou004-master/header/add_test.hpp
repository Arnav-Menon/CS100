#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"

TEST(AddTest, OpEvaluteNonZero)
{
	Base* num1 = new Op(5.0);
	Base* num2 = new Op(2.0);
	Base* test = new Add(num1, num2);
	EXPECT_EQ(test -> evaluate(),7.0);
}

#endif //__ADD_TEST_HPP__
