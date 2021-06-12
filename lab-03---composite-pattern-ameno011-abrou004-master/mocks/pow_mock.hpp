#ifndef __POW_MOCK_OP__
#define __POW_MOCK_OP__

#include "../header/base.hpp"
#include "../header/pow.hpp"

#include <iostream>
using namespace std;

class PowMock: public Base
{
    public:
        PowMock(Base* obj): Base(), val(obj) { }

        virtual double evaluate() { return val->evaluate(); }
        virtual string stringify() { return val->stringify(); }
    private:
	Base* val;
};

#endif //__POW_MOCK_HPP__

