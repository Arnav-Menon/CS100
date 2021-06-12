#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

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


TEST(AddTest,ZeroAddition)
{
	Base* zero = new Op(0);
	Base* test = new Add(zero,zero);
	VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test),"${({0}+{0})}$");
	delete zero;
	delete test;
	delete latex;
}

TEST(AddTest,ZeroAndNumAddition)
{
        Base* zero = new Op(0);
        Base* one = new Op(1);
        Base* test = new Add(zero,one);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test),"${({0}+{1})}$");
	delete zero;
	delete one;
	delete test;
	delete latex;
}

TEST(AddTest,SimpleAddition)
{
        Base* one = new Op(1);
        Base* two = new Op(2);
        Base* test = new Add(one,two);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test),"${({1}+{2})}$");
	delete one;
	delete two;
	delete test;
	delete latex;
}

TEST(AddTest,MultipleAddition)
{
        Base* one = new Op(1);
        Base* two = new Op(2);
	Base* three = new Op(3);
	Base* four = new Op(4);
        Base* fir = new Add(one,two);
	Base* sec = new Add(fir, three);
	Base* fin = new Add(sec, four); 
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin),"${((({1}+{2})+{3})+{4})}$");
	delete one;
	delete two;
	delete three;
	delete four;
	delete fir;
	delete sec;
	delete fin;
	delete latex;
}

TEST(AddTest,NegAddition)
{
        Base* neg_five = new Op(-5);
        Base* neg_ten = new Op(-10);
        Base* test = new Add(neg_five,neg_ten);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(test),"${({-5}+{-10})}$");
	delete neg_five;
	delete neg_ten;
	delete test;
	delete latex;
}

TEST(AddTest,PosNegAddition)
{
        Base* neg_five = new Op(-5);
        Base* neg_ten = new Op(-10);
	Base* fifteen = new Op(15);
        Base* fir = new Add(neg_five,neg_ten);
	Base* fin = new Add(fir, fifteen);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin), "${(({-5}+{-10})+{15})}$");
	delete neg_five;
	delete neg_ten;
	delete fifteen;
	delete fir;
	delete fin;
	delete latex;
}

TEST(AddTest,AdditionSubtraction)
{
        Base* five = new Op(5);
        Base* neg_ten = new Op(-10);
        Base* fifteen = new Op(15);
        Base* fir = new Add(five,neg_ten);
	Base* fin = new Sub(fir, fifteen);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin),"${(({5}+{-10})-{15})}$");
	delete five;
	delete neg_ten;
	delete fifteen;
	delete fir;
	delete fin;
	delete latex;
}

TEST(AddTest,AdditionMult)
{
        Base* five = new Op(5);
        Base* two = new Op(2);
        Base* ten = new Op(10);
        Base* fir = new Mult(five,two);
        Base* fin = new Add(fir, ten);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin),"${(({5}\\cdot{2})+{10})}$");
	delete five;
	delete two;
	delete ten;
	delete fir;
	delete fin;
	delete latex;
}

TEST(AddTest,AdditionDiv)
{
        Base* five = new Op(5);
        Base* three = new Op(3);
        Base* ten = new Op(10);
        Base* fir = new Add(five,ten);
        Base* fin = new Div(fir, three);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin),"${\\frac{({5}+{10})}{{3}}}$");
	delete five;
	delete three;
	delete ten;
	delete fir;
	delete fin;
	delete latex;
}

TEST(AddTest,AdditionPow)
{
        Base* two = new Op(2);
        Base* three = new Op(3);
        Base* ten = new Op(10);
        Base* fir = new Pow(two,three);
        Base* fin = new Add(fir, ten);
        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ(latex->PrintLatex(fin),"${(({2}^{3})+{10})}$");
	delete two;
	delete three;
	delete ten;	
	delete fir;
	delete fin;
	delete latex;
}

#endif //__ADD_TEST_HPP__
