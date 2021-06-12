#include <iostream>

#include "../header/base.hpp"
#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/pow.hpp"
#include "../header/sub.hpp"

#include "../header/iterator.hpp"
#include "../header/visitorLatex.hpp"

using namespace std;

int main() {
	
	Base* three = new Op(3);
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* two = new Op(2);
	Base* mult = new Mult(seven, four);
	Base* add = new Add(three, mult);
	Base* minus = new Sub(add, two);	

	Base* one = new Op(1);
	Base* five = new Op(5);
	Base* zero = new Op(0);
	Base* sub = new Sub(five, zero);
	Base* add1 = new Add(one, sub);

	Base* pow = new Pow(five, two);

	Base* mult1 = new Mult(two, five);

	Base* frac = new Div(two, three);

	Base* mult2 = new Mult(two, five);
	Base* pow1 = new Pow(five, two);
	Base* frac2 = new Div(mult2, pow1);

	VisitorLatex* latex = new VisitorLatex();
	VisitorLatex* latex1 = new VisitorLatex();
	VisitorLatex* latex2 = new VisitorLatex();
	VisitorLatex* latex3 = new VisitorLatex();
	VisitorLatex* latex4 = new VisitorLatex();
	VisitorLatex* latex5 = new VisitorLatex();
	
	cout << latex->PrintLatex(minus) << endl;
	cout << latex1->PrintLatex(add1) << endl;
	cout << latex2->PrintLatex(pow) << endl;
	cout << latex3->PrintLatex(mult1) << endl;
	cout << latex4->PrintLatex(frac) << endl;
	cout << latex5->PrintLatex(frac2) << endl;

	delete three;
	delete seven;
	delete four;
	delete two;
	delete mult;
	delete add;
	delete minus;
	
	delete one;
	delete five;
	delete zero;
	delete sub;
	delete add1;

	delete pow;
	
	delete mult1;
	
	delete frac;

	delete mult2;
	delete pow1;
	delete frac2;
	
	delete latex;
	delete latex1;
	delete latex2;
	delete latex3;
	delete latex4;
	delete latex5;
	
	return 0;
}
