#ifndef __TF_HPP__
#define __TF_HPP__

#include "type.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TF: public Type {
      
    public:
        TF() : Type() {}
        //if type points to a TF class, type->Display() will call the Display() function of the TF class	
        virtual void Display(GameQuestion* gq, std::ostream& out) const {
                out << "\t" << gq->GetQuestion() << endl;
                out << "\t\t True" << endl;
                out << "\t\t False" << endl;
        }
};

#endif // __TF_HPP__
