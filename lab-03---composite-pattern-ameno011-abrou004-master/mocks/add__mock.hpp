#ifndef __ADD_MOCK_OP__
#define __ADD_MOCK_OP__

#include "../header/base.hpp"
#include "../header/add.hpp"

#include <iostream>
using namespace std;

class AddMock: public Base
{
    public:
        AddMock() { }

        virtual double evaluate() { return 20.5 ; }
        virtual string stringify() { return "20.5"; }
}

#endif //__ADD_MOCK_HPP__
