#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"

#include <string>
#include <iostream>

using namespace std;

class Op;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class VisitorLatex : public Visitor {

	public:
		VisitorLatex() { } 
		virtual ~VisitorLatex() = default;
		string PrintLatex(Base* ptr) {
			latexString += "${";
			for (Iterator it(ptr); !it.is_done(); it.next()) {
				it.current_node()->accept(this, it.current_index());
			}
			latexString += "}$";
			return latexString;
		}

	//Nodes with no children are visited only once (index = 0)
	virtual void visit_op(Op* ptr){ latexString += "{" + ptr->stringify() + "}"; }
	//virtual void visit_rand(Rand* ptr){ latexString += "{" + ptr->stringify() + "}";}
 
	// Nodes with two children are visited three times.
	// index = 0 -> begin
	// index = 1 -> middle
	// index = 2 -> end
	virtual void visit_add_begin(Add* ptr){ latexString += "("; }
	virtual void visit_add_middle(Add* ptr){ latexString += "+"; }
	virtual void visit_add_end(Add* ptr){ latexString += ")"; }
	virtual void visit_sub_begin(Sub* ptr){ latexString += "("; }
	virtual void visit_sub_middle(Sub* ptr){ latexString += "-"; }
	virtual void visit_sub_end(Sub* ptr){ latexString += ")"; }
	virtual void visit_mult_begin(Mult* ptr){ latexString += "("; }
	virtual void visit_mult_middle(Mult* ptr){ latexString += "\\cdot"; }
	virtual void visit_mult_end(Mult* ptr){ latexString += ")";}
	virtual void visit_div_begin(Div* ptr){ latexString += "\\frac{"; }
	virtual void visit_div_middle(Div* ptr){ latexString += "}{"; }
	virtual void visit_div_end(Div* ptr){ latexString += "}"; }
	virtual void visit_pow_begin(Pow* ptr){ latexString += "("; }
	virtual void visit_pow_middle(Pow* ptr){ latexString += "^"; }
	virtual void visit_pow_end(Pow* ptr){ latexString += ")"; }

	private:
		string latexString;
	
};

#endif // __VISITORLATEX_HPP__
