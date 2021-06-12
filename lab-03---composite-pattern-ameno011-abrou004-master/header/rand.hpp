#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class Rand : public Base {
    public:
        Rand() : Base(), num(rand() % 100) { }
        virtual double evaluate() { return num; }
        virtual std::string stringify() {
                ostringstream ss;
                ss << setprecision(8) << num;
                return ss.str();
        }

    private:
        double num;
};

#endif // __RAND_HPP__
