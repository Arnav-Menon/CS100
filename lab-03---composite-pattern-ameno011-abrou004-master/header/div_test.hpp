#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "mult.hpp"

#include "../mocks/add_mock.hpp"
#include "../mocks/sub_mock.hpp"
#include "../mocks/pow_mock.hpp"

TEST(DivTest, EvaluateNonZeros) {
        Base* eight = new Op(8);
	Base* seven = new Op(7);
	Base* test = new Div(eight, seven);
        EXPECT_EQ(test->stringify(), "(8 / 7)");
        EXPECT_NEAR(test->evaluate(), 1.14286, 0.0001);
}

TEST(DivTest, EvaluateZero) {
	Base* zero = new Op(0);
	Base* sixty_six = new Op(66);
        Base* test = new Div(zero, sixty_six); 
        EXPECT_EQ(test->stringify(), "(0 / 66)");
        EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, EvaluateNegative) {
	Base* neg_thirteen = new Op(-13);
	Base* forty_nine = new Op(49);
        Base* test = new Div(neg_thirteen, forty_nine);
        EXPECT_EQ(test->stringify(), "(-13 / 49)");
        EXPECT_NEAR(test->evaluate(), -0.265306, 0.0001);
}

TEST(DivTest, EvaluateDoubleNegative) {
        Base* neg_nine = new Op(-9);
	Base* neg_four = new Op(-4);
	Base* test = new Div(neg_nine, neg_four);
        EXPECT_EQ(test->stringify(), "(-9 / -4)");
        EXPECT_NEAR(test->evaluate(), 2.25, 0.0001);
}

TEST(DivTest, MultipleDivObjs) {
	Base* eight = new Op(8);
	Base* two = new Op(2);
	Base* four = new Op(4);
	Base* div1 = new Div(eight, two);
	Base* div2 = new Div(div1, four);
	EXPECT_EQ(div2->stringify(), "((8 / 2) / 4)");
	EXPECT_NEAR(div2->evaluate(), 1, 0.0001);
}

TEST(DivTest, DidivdeAndMultiply) {
	Base* forty_nine = new Op(49);
	Base* seven = new Op(7);
	Base* five = new Op(5);
	Base* div = new Div(forty_nine, seven);
	Base* mult = new Mult(div, five);
	EXPECT_EQ(mult->stringify(), "((49 / 7) * 5)");
	EXPECT_EQ(mult->evaluate(), 35);
}

TEST(DivTest, AddMock) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
        Base* add = new AddMock(eighteen);
        Base* div = new Div(add, two);
        EXPECT_EQ(div->stringify(), "(18 / 2)");
        EXPECT_EQ(div->evaluate(), 9);
}

TEST(DivTest, SubMock) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
        Base* sub = new SubMock(eighteen);
        Base* div = new Div(sub, two);
        EXPECT_EQ(div->stringify(), "(18 / 2)");
        EXPECT_EQ(div->evaluate(), 9);
}

TEST(DivTest, PowMock) {
        Base* nine = new Op(9);
        Base* two = new Op(2);
        Base* pow = new PowMock(nine);
        Base* div = new Div(pow, two);
        EXPECT_EQ(div->stringify(), "(9 / 2)");
        EXPECT_EQ(div->evaluate(), 4.5);
}

// still unsure if this test implementation is coreect...
TEST(DivTest, EvaluateDivideZero) {
        Base* sixteen = new Op(16);
	Base* zero = new Op(0);
	Base* test = new Div(sixteen, zero);
        EXPECT_EQ(test->stringify(), "(16 / 0)");
	try {
		test->evaluate();
	}
	catch ( ... ) {
		FAIL() << "ERROR: " << std::current_exception << std::endl;		
	}
}

#endif // __DIV_TEST_HPP__
