#ifndef __SUB_MOCK_OP__
#define __SUB_MOCK_OP__

#include "../header/base.hpp"
#include "../header/sub.hpp"

#include <iostream>
using namespace std;

class SubMock: public Base
{
    public:
        SubMock(Base* obj): Base(), val(obj) { }

        virtual double evaluate() { return val->evaluate(); }
        virtual string stringify() { return val->stringify(); }
    private:
	Base* val;
};

#endif //__SUB_MOCK_HPP__

