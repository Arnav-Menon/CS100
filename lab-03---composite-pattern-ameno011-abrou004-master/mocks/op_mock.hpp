#ifndef __OP_MOCK_HPP__
#define __OP_MOCK_HPP__

#include "../header/base.hpp"
#include "../header/op.hpp"
#include <iostream>

using namespace std; 

class SevenOpMock: public Base
{
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
}

#endif // __OP_MOCK_HPP__
