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
/*		~Mult() {
			if (val1 != nullptr) delete val1; 
			if (val2 != nullptr) delete val2;
		}*/
		virtual double evaluate() { return val1->evaluate() * val2->evaluate(); }
		virtual std::string stringify() {
			ostringstream ss;
			ss << setprecision(8) << "(" << val1->stringify() << "*" << val2->stringify() << ")";
			return ss.str();
		}
		virtual int number_of_children() { return 2; } 
                virtual Base* get_child(int index) {
                        if (index == 0) return val1;
                        else if (index == 1) return val2;
                        else return nullptr;
                }
		virtual void accept(Visitor* v, int index) {
			if (index == 0) v->visit_mult_begin(this);
			else if (index == 1) v->visit_mult_middle(this);
			else v->visit_mult_end(this);
		}
	private:
		Base* val1;
		Base* val2;
};

#endif //__MULT_HPP__
