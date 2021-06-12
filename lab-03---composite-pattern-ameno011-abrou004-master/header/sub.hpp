#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <iostream>
#include "base.hpp"
#include <sstream>
#include <iomanip>

using namespace std;

class Sub : public Base
{
        public:
                Sub (Base* num1, Base* num2 ) : Base(),x(num1), y(num2){}
                virtual double evaluate() {return x->evaluate() - y->evaluate();}
                virtual std::string stringify()
                {
                        ostringstream ss;
                        ss << setprecision (8) << "(" <<x->stringify() << " -  "  << y->stringify() << ")";
                        return ss.str();
                }
        private:
                Base* x;
                Base* y;

};

#endif //__SUB_HPP__

