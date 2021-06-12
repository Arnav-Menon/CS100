#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/pow.hpp"
#include "../header/base.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"

#include "../src/iterator.cpp"
#include "../header/visitorLatex.hpp"

TEST(DivTest, EvaluateNonZeros) {
        Base* eight = new Op(8);
	Base* seven = new Op(7);
	Base* test = new Div(eight, seven);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test), "${\\frac{{8}}{{7}}}$");
	delete eight;
	delete seven;
	delete test;
	delete latex;
}

TEST(DivTest, EvaluateZero) {
	Base* zero = new Op(0);
	Base* sixty_six = new Op(66);
        Base* test = new Div(zero, sixty_six); 
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${\\frac{{0}}{{66}}}$");
	delete zero;
	delete sixty_six;
	delete test;
	delete latex;
}

TEST(DivTest, EvaluateNegative) {
	Base* neg_thirteen = new Op(-13);
	Base* forty_nine = new Op(49);
        Base* test = new Div(neg_thirteen, forty_nine);
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${\\frac{{-13}}{{49}}}$");
	delete neg_thirteen;
	delete forty_nine;
	delete test;
	delete latex;
}

TEST(DivTest, EvaluateDoubleNegative) {
        Base* neg_nine = new Op(-9);
	Base* neg_four = new Op(-4);
	Base* test = new Div(neg_nine, neg_four);
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${\\frac{{-9}}{{-4}}}$");
	delete neg_nine;
	delete neg_four;
	delete test;
	delete latex;
}

TEST(DivTest, MultipleDivObjs) {
	Base* eight = new Op(8);
	Base* two = new Op(2);
	Base* four = new Op(4);
	Base* div1 = new Div(eight, two);
	Base* div2 = new Div(div1, four);
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(div2), "${\\frac{\\frac{{8}}{{2}}}{{4}}}$");
	delete eight;
	delete two;
	delete four;
	delete div1;
	delete div2;
	delete latex;
}

TEST(DivTest, DidivdeAndMultiply) {
	Base* forty_nine = new Op(49);
	Base* seven = new Op(7);
	Base* five = new Op(5);
	Base* div = new Div(forty_nine, seven);
	Base* mult = new Mult(div, five);
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(mult), "${(\\frac{{49}}{{7}}\\cdot{5})}$");
	delete forty_nine;
	delete seven;
	delete five;
	delete div;
	delete mult;
	delete latex;
}

TEST(DivTest, DivAdd) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
	Base* three = new Op(3);
        Base* add = new Add(eighteen, two);
        Base* div = new Div(add, three);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(div), "${\\frac{({18}+{2})}{{3}}}$");
	delete eighteen;
	delete two;
	delete three;
	delete add;
	delete div;
	delete latex;	
}

TEST(DivTest, DivMock) {
        Base* eighteen = new Op(18);
        Base* two = new Op(2);
        Base* seven = new Op(-7);
	Base* sub = new Sub(eighteen, seven);
        Base* div = new Div(sub, two);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(div), "${\\frac{({18}-{-7})}{{2}}}$");
	delete eighteen;
	delete two;
	delete seven;
	delete sub;
	delete div;
	delete latex;
}

TEST(DivTest, DivPow) {
        Base* nine = new Op(9);
        Base* two = new Op(2);
	Base* nineteen = new Op(19);
        Base* pow = new Pow(nine, nineteen);
        Base* div = new Div(pow, two);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(div), "${\\frac{({9}^{19})}{{2}}}$");
	delete nine;
	delete two;
	delete nineteen;
	delete pow;
	delete div;
	delete latex;
}

#endif 
