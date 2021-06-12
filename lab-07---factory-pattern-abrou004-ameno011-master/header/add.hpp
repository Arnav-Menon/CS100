#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <iostream>
#include "base.hpp"
#include <sstream>
#include <iomanip>

using namespace std;

class Add : public Base
{
        public:
                Add (Base* num1, Base* num2 ) : Base(),x(num1), y(num2){}
                ~Add() {delete x; delete y;}
		virtual double evaluate() {return x->evaluate() + y->evaluate();}
                virtual std::string stringify()
                {
                        ostringstream ss;
                        ss << setprecision (8) << "(" <<x->stringify() << " + "  << y->stringify() << ")";
                        return ss.str();
                }
        private:
                Base* x;
                Base* y;

};

#endif //__ADD_HPP__
