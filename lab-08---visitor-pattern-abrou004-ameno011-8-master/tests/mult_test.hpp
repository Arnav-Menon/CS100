#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

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

TEST(MultTest, EvaluateNonZeros) {
        Base* eight = new Op(8);
	Base* seven = new Op(7);
	Base* test = new Mult(eight, seven);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test), "${({8}\\cdot{7})}$");
	delete eight;
	delete seven;
	delete test;
	delete latex;
}

TEST(MultTest, EvaluateZero) {
	Base* zero = new Op(0);
	Base* sixty_six = new Op(66);
        Base* test = new Mult(zero, sixty_six); 
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({0}\\cdot{66})}$");
	delete zero;
	delete sixty_six;
	delete test;
	delete latex;
}

TEST(MultTest, EvaluateNegative) {
	Base* neg_thirteen = new Op(-13);
	Base* forty_nine = new Op(49);
        Base* test = new Mult(neg_thirteen, forty_nine);
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({-13}\\cdot{49})}$");
	delete neg_thirteen;
	delete forty_nine;
	delete test;
	delete latex;
}

TEST(MultTest, EvaluateDoubleNegative) {
        Base* neg_nine = new Op(-9);
	Base* neg_four = new Op(-4);
	Base* test = new Mult(neg_nine, neg_four);
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({-9}\\cdot{-4})}$");
	delete neg_nine;
	delete neg_four;
	delete test;
	delete latex;
}

TEST(MultTest, MultipleMultObjs) {
	Base* eight = new Op(8);
	Base* two = new Op(2);
	Base* four = new Op(4);
	Base* div1 = new Mult(eight, two);
	Base* div2 = new Mult(div1, four);
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(div2), "${(({8}\\cdot{2})\\cdot{4})}$");
	delete eight;
	delete two;
	delete four;
	delete div1;
	delete div2;
	delete latex;
}

TEST(MultTest, DidivdeAndMultiply) {
	Base* forty_nine = new Op(49);
	Base* seven = new Op(7);
	Base* five = new Op(5);
	Base* div = new Mult(forty_nine, seven);
	Base* mult = new Div(div, five);
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(mult), "${\\frac{({49}\\cdot{7})}{{5}}}$");
	delete forty_nine;
	delete seven;
	delete five;
	delete div;
	delete mult;
	delete latex;
}

TEST(MultTest, MultAdd) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
	Base* three = new Op(3);
        Base* add = new Add(eighteen, two);
        Base* div = new Mult(add, three);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(div), "${(({18}+{2})\\cdot{3})}$");
	delete eighteen;
	delete two;
	delete three;
	delete add;
	delete div;
	delete latex;
}

TEST(MultTest, MultSub) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
        Base* seven = new Op(-7);
	Base* sub = new Sub(eighteen, seven);
        Base* div = new Mult(sub, two);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(div), "${(({18}-{-7})\\cdot{2})}$");
	delete eighteen;
	delete two;
	delete seven;
	delete sub;
	delete div;
	delete latex;
}

TEST(MultTest, MultPow) {
        Base* nine = new Op(9);
        Base* two = new Op(2);
	Base* nineteen = new Op(19);
        Base* pow = new Pow(nine, nineteen);
        Base* div = new Mult(pow, two);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(div), "${(({9}^{19})\\cdot{2})}$");
	delete nine;
	delete two;
	delete nineteen;
	delete pow;
	delete div;
	delete latex;
}

#endif // __MULT_TEST_HPP__
