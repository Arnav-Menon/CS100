#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"
#include "div.hpp"

#include "../mocks/add_mock.hpp"
#include "../mocks/sub_mock.hpp"
#include "../mocks/pow_mock.hpp"


TEST(MultTest, EvaluateNonZeros) {
	Base* seven = new Op(7);
	Base* eight = new Op(8);
	Base* test = new Mult(seven, eight);
	EXPECT_EQ(test->stringify(), "(7 * 8)");
	EXPECT_EQ(test->evaluate(), 56);
}

TEST(MultTest, EvaluateZero) {
	Base* zero = new Op(0);
	Base* sixtysix = new Op(66);
	Base* seven = new Op(7);
        Base* test = new Mult(zero, sixtysix);
        Base* test1 = new Mult(test, seven);
	EXPECT_EQ(test1->stringify(), "((0 * 66) * 7)");
        EXPECT_EQ(test1->evaluate(), 0);
}

TEST(MultTest, EvaluateNegative) {
	Base* neg_thirteen = new Op(-13);
	Base* forty_nine = new Op(49);
        Base* test = new Mult(neg_thirteen, forty_nine);
        EXPECT_EQ(test->stringify(), "(-13 * 49)");
        EXPECT_EQ(test->evaluate(), -637);
}

TEST(MultTest, EvaluateDoubleNegative) {
	Base* neg_nine = new Op(-9);
	Base* neg_four = new Op(-4);
        Base* test = new Mult(neg_nine, neg_four);
        EXPECT_EQ(test->stringify(), "(-9 * -4)");
	EXPECT_EQ(test->evaluate(), 36);
}

TEST(MultTest, MultiplyAndDivide) {
	Base* five = new Op(5);
	Base* six = new Op(6);
	Base* three = new Op(3);
	Base* mult = new Mult(five, six);
	Base* div = new Div(mult, three);
	EXPECT_EQ(div->stringify(), "((5 * 6) / 3)");
	EXPECT_EQ(div->evaluate(), 10);
}

TEST(MultTest, AddMock) {
	Base* nineteen = new Op(19);
	Base* two = new Op(2);
	Base* add = new AddMock(nineteen);
	Base* mult = new Mult(two, add);
	EXPECT_EQ(mult->stringify(), "(2 * 19)");
	EXPECT_EQ(mult->evaluate(), 38);
}

TEST(MultTest, SubMock) {
        Base* nineteen = new Op(19);
        Base* two = new Op(2);
        Base* sub = new SubMock(nineteen);
        Base* mult = new Mult(two, sub);
        EXPECT_EQ(mult->stringify(), "(2 * 19)");
        EXPECT_EQ(mult->evaluate(), 38);
}

TEST(MultTest, PowMock) {
        Base* nine = new Op(9);
        Base* two = new Op(2);
        Base* pow = new PowMock(nine);
        Base* mult = new Mult(two, pow);
        EXPECT_EQ(mult->stringify(), "(2 * 9)");
        EXPECT_EQ(mult->evaluate(), 18);
}

#endif // __MULT_TEST_HPP__
