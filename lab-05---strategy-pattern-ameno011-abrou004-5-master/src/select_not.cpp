#include "../header/select_not.hpp"

#include <iostream>
#include <string>

using namespace std;

Select_Not::Select_Not(Select_Column* one) : Select_Column(one) {
	col1 = cond1->get_column();
	//cout << "Created NOT" << endl;
}

bool Select_Not::select(const string& s) const {
	if (cond1->select(s)) return false;
	return true;
}
