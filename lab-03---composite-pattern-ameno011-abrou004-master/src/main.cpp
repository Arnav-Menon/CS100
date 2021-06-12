#include <iostream>

#include "../header/base.hpp"
#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/add.hpp"
#include "../header/pow.hpp"
#include "../header/sub.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    
    // test 1
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* sixteen = new Pow(four, two);
    Base* mult = new Mult(seven, four);
    Base* div = new Div(mult, two);
    Base* add = new Add(div, sixteen);
    Base* sub = new Sub(add, div);
    Base* minus = new Sub(sub, three);

    // test 2
    Base* rand = new Rand();
    Base* six= new Op(6);
    Base* pow = new Pow(rand, seven);

    // test 3
    Base* five = new Op(5);
    Base* rand1 = new Rand();
    Base* zero = new Op(0);
    Base* sub1 = new Sub(three, rand1);
    Base* div1 = new Div(sub1, three);
    Base* add1 = new Add(div1, rand1);
    Base* mult1 = new Mult(add1, zero);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    std::cout << pow->stringify() << " = " << pow->evaluate() << std::endl;
    std::cout << mult1->stringify() << " = " << mult1->evaluate() << std::endl;
    return 0;
}
