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
              /*  ~Sub() {
			if (x != nullptr) delete x; 
			if (y != nullptr) delete y;
		}*/
		virtual double evaluate() {return x->evaluate() - y->evaluate();}
                virtual std::string stringify()
                {
                        ostringstream ss;
                        ss << setprecision (8) << "(" <<x->stringify() << "-"  << y->stringify() << ")";
                        return ss.str();
                }
                virtual int number_of_children() { return 2; }
                virtual Base* get_child(int index) {
                        if (index == 0) return x;
                        else if (index == 1) return y;
                        else return nullptr;
                }
		virtual void accept(Visitor* v, int index) {
			if (index == 0) v->visit_sub_begin(this);
			else if (index == 1) v->visit_sub_middle(this);
			else v->visit_sub_end(this);
		}
        private:
                Base* x;
                Base* y;

};

#endif //__SUB_HPP__
