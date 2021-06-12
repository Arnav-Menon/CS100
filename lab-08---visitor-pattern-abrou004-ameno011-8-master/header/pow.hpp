#ifndef __POW_HPP__
#define __POW_HPP__

#include <iostream>
#include "base.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Pow : public Base
{
        public:
                Pow (Base* num1, Base* num2 ) : Base(),x(num1), y(num2){}
               // ~Pow() {delete x; delete y;}
		virtual double evaluate()
		{
			return(pow( x->evaluate(), y->evaluate()));
		}
                virtual std::string stringify()
                {
                        ostringstream ss;
                        ss << setprecision (8) << "(" <<x->stringify() << "^"  << y->stringify() << ")";
                        return ss.str();
                }
                virtual int number_of_children() { return 2; }
                virtual Base* get_child(int index) {
                        if (index == 0) return x;
                        else if (index == 1) return y;
                        else return nullptr;
                }
		virtual void accept(Visitor* v, int index) {
			if (index == 0) v->visit_pow_begin(this);
			else if (index == 1) v->visit_pow_middle(this);
			else v->visit_pow_end(this);
		}
        private:
                Base* x;
                Base* y;

};

#endif //__POW_HPP__
