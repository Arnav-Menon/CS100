#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"

#include <string>
#include <iostream>

using namespace std;

class Select_Or : public Select {
	private:
		Select* p1;
		Select* p2;
	public:
		Select_Or(Select* one, Select* two) {
			p1 = one;
			p2 = two;
		}
	
		~Select_Or() {
			delete p1;
			delete p2;
		}

		virtual bool select(const Spreadsheet* sheet, int row) const {
			return (p1->select(sheet, row) || p2->select(sheet, row));
		}
};

#endif // __SELECT_OR_HPP__
