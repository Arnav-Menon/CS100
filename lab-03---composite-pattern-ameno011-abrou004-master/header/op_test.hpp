#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"

TEST(OpTest, OpEvaluateNonZero)
{
	Base* test = new Op(8.0);
	EXPECT_EQ(test->evaluate(), 8);
}

TEST(AddTest, OpEvaluateNonZero)
{
	Base* num1 = new Op(2.0);
	Base* num2 = new Op(3.0);
	Base* test = new Add(num1, num2);
	EXPECT_EQ(test-> evaluate(),5.0);
}

#endif //__OP_TEST_HPP__
