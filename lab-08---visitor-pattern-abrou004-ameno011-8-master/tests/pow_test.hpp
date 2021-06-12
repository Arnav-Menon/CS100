#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/pow.hpp"
#include "../header/base.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"

#include "../header/visitorLatex.hpp"

TEST(PowTest, EvaluateNonZeros) {
        Base* eight = new Op(8);
	Base* seven = new Op(7);
	Base* test = new Pow(eight, seven);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test), "${({8}^{7})}$");
	delete eight;
	delete seven;
	delete test;
	delete latex;
}

TEST(PowTest, EvaluateZero) {
	Base* zero = new Op(0);
	Base* sixty_six = new Op(66);
        Base* test = new Pow(zero, sixty_six); 
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({0}^{66})}$");
	delete zero;
	delete sixty_six;
	delete test;
	delete latex;
}

TEST(PowTest, EvaluateNegative) {
	Base* neg_thirteen = new Op(-13);
	Base* forty_nine = new Op(49);
        Base* test = new Pow(neg_thirteen, forty_nine);
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({-13}^{49})}$");
	delete neg_thirteen;
	delete forty_nine;
	delete test;
	delete latex;
}

TEST(PowTest, EvaluateDoubleNegative) {
        Base* neg_nine = new Op(-9);
	Base* neg_four = new Op(-4);
	Base* test = new Pow(neg_nine, neg_four);
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({-9}^{-4})}$");
	delete neg_nine;
	delete neg_four;
	delete test;
	delete latex;
}

TEST(PowTest, MultiplePowObjs) {
	Base* eight = new Op(8);
	Base* two = new Op(2);
	Base* four = new Op(4);
	Base* div1 = new Pow(eight, two);
	Base* div2 = new Pow(div1, four);
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(div2), "${(({8}^{2})^{4})}$");
	delete eight;
	delete two;
	delete four;
	delete div1;
	delete div2;
	delete latex;
}

TEST(PowTest, PowAndMultiply) {
	Base* forty_nine = new Op(49);
	Base* seven = new Op(7);
	Base* five = new Op(5);
	Base* div = new Mult(forty_nine, seven);
	Base* pow = new Pow(div, five);
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(pow), "${(({49}\\cdot{7})^{5})}$");
	delete forty_nine;
	delete seven;
	delete five;
	delete div;
	delete pow;
	delete latex;
}

TEST(PowTest, PowAdd) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
	Base* three = new Op(3);
        Base* add = new Add(eighteen, two);
        Base* pow = new Pow(add, three);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(pow), "${(({18}+{2})^{3})}$");
	delete eighteen;
	delete two;
	delete three;
	delete add;
	delete pow;
	delete latex;
}

TEST(PowTest, PowSub) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
        Base* seven = new Op(-7);
	Base* sub = new Sub(eighteen, seven);
        Base* pow = new Pow(sub, two);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(pow), "${(({18}-{-7})^{2})}$");
	delete eighteen;
	delete two;
	delete seven;
	delete sub;
	delete pow;
	delete latex;
}

TEST(PowTest, PowMult) {
        Base* nine = new Op(9);
        Base* two = new Op(2);
	Base* nineteen = new Op(19);
        Base* mult = new Mult(nine, nineteen);
        Base* pow = new Pow(mult, two);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(pow), "${(({9}\\cdot{19})^{2})}$");
	delete nine;
	delete two;
	delete nineteen;
	delete mult;
	delete pow;
	delete latex;
}

#endif // __POW_TEST_HPP__
