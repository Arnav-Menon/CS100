#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Div : public Base {
        public:
                Div(Base* num1, Base* num2) : Base(), val1(num1), val2(num2) { }
                ~Div() {delete val1; delete val2;}
		virtual double evaluate() { return val1->evaluate() / val2->evaluate(); }
                virtual std::string stringify() {
                        ostringstream ss;
                        ss << setprecision(8) << "(" << val1->stringify() << " / " << val2->stringify() << ")";
                        return ss.str();
                }
        private:
                Base* val1;
                Base* val2;
};

#endif //__DIV_HPP__
