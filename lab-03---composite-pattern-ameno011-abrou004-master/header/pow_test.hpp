#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"

TEST(PowTest, OpEvaluateNonZero)
{
	Base* x = new Op(2.0);
	Base* y = new Op(3.0);
	Base* test = new Pow(x,y);
	EXPECT_EQ (test -> evaluate(),8.0);
        
}

#endif //__POW_TEST_HPP
