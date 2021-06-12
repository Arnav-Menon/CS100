#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/pow.hpp"
#include "../header/base.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"

//#include "../header/visitorLatex.hpp"

TEST(SubTest, ZeroSub)
{
	Base* zero = new Op(0);
        Base* test = new Sub(zero, zero); 
        VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ(latex->PrintLatex(test), "${({0}-{0})}$");
	delete zero;
	delete test;
	delete latex;
}

TEST(SubTest, ZeroNumSub)
{
        Base* one = new Op(1);
        Base* zero = new Op(0);
        Base* test = new Sub(one, zero);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test), "${({1}-{0})}$");
	delete one;
	delete zero;
	delete test;
	delete latex;
}

TEST(SubTest, SimpleSub)
{
        Base* two = new Op(2);
	Base* one = new Op(1);
        Base* test = new Sub(two, one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test), "${({2}-{1})}$");
	delete two;	
	delete one;
	delete test;
	delete latex;
}

TEST(SubTest, MultipleSub)
{
	Base* five = new Op(5);       
	Base* two = new Op(2);
        Base* one = new Op(1);
	Base* fir = new Sub(five, two);
        Base* fin = new Sub(fir, one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${(({5}-{2})-{1})}$");
	delete five;
	delete two;
	delete one;
	delete fir;
	delete fin;
	delete latex;
}

TEST(SubTest, NegSub)
{
        Base* neg_two = new Op(-2);
        Base* neg_one = new Op(-1);
        Base* test = new Sub(neg_two, neg_one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test), "${({-2}-{-1})}$");
	delete neg_two;
	delete neg_one;
	delete test;
	delete latex;
}

TEST(SubTest,PosNegSub)
{
	Base* three = new Op(3); 
	Base* two = new Op(2);
        Base* neg_one = new Op(-1);
	Base* fir = new Sub(three, two);
        Base* fin = new Sub(fir, neg_one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${(({3}-{2})-{-1})}$");
	delete three;
	delete two;
	delete neg_one;
	delete fir;
	delete fin;
	delete latex;
}

TEST(SubTest,AddSub)
{
        Base* three = new Op(3);
        Base* two = new Op(2);
        Base* one = new Op(1);
        Base* fir = new Add(three, two);
        Base* fin = new Sub(fir, one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${(({3}+{2})-{1})}$");
	delete three;
	delete two;
	delete one;
	delete fir;
	delete fin;
	delete latex;
}

TEST(SubTest,MultSub)
{
        Base* five = new Op(5);
        Base* two = new Op(2);
        Base* one = new Op(1);
        Base* fir = new Mult(five, two);
        Base* fin = new Sub(fir,one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${(({5}\\cdot{2})-{1})}$" );
	delete five;
	delete two;
	delete one;
	delete fir;
	delete fin;
	delete latex;
}

TEST(SubTest,DivSub)
{
        Base* eight = new Op(8);
        Base* four = new Op(4);
        Base* two = new Op(2);
        Base* fir = new Sub(eight, two);
        Base* fin = new Div(fir,two);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${\\frac{({8}-{2})}{{2}}}$");
	delete eight;
	delete four;
	delete two;
	delete fir;
	delete fin;
	delete latex;
}

TEST(SubTest,PowSub)
{
        Base* five = new Op(5);
        Base* two = new Op(2);
        Base* one = new Op(1);
        Base* fir = new Pow(five, two);
        Base* fin = new Sub(fir,one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${(({5}^{2})-{1})}$");
	delete five;
	delete two;
	delete one;
	delete fir;
	delete fin;
	delete latex;
}


#endif //__SUB_TEST_HPP__
