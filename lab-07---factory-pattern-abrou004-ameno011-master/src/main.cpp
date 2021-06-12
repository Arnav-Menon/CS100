#include <iostream>

#include "../header/base.hpp"
//#include "../header/div.hpp"
//#include "../header/mult.hpp"
//#include "../header/op.hpp"
//#include "../header/rand.hpp"
//#include "../header/add.hpp"
//#include "../header/pow.hpp"
//#include "../header/sub.hpp"
#include "../header/factory.hpp"

using namespace std;

int main(int argc, char** argv) {

    Factory* f = new Factory();
    Base* output = f->parse(argv, argc);
    
    if (output == nullptr)
	cout << "Error. Please try again" << endl;
    else {
	cout << "input: " << output->stringify() << endl;
	cout << "answer: " << output->evaluate() << endl;
    }
	
    delete f;
    delete output;
    return 0;
}
