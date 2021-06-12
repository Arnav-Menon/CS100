#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Mult : public Base {
	public:
		Mult(Base* num1, Base* num2) : Base(), val1(num1), val2(num2) { }
		virtual double evaluate() { return val1->evaluate() * val2->evaluate(); }
		virtual std::string stringify() {
			ostringstream ss;
			ss << setprecision(8) << "(" << val1->stringify() << " * " << val2->stringify() << ")";
			//ss << " INSIDE MULT CLASS";
			return ss.str();
		}
	private:
		Base* val1;
		Base* val2;
};

#endif //__MULT_HPP__
