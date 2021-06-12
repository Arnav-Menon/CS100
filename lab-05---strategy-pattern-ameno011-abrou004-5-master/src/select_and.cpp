#include "../header/select_and.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Select_And::Select_And(Select_Column* one, Select_Column* two) : Select_Column(one, two) {
	col1 = cond1->get_column();
	col2 = cond2->get_column();
	check = true;
}

bool Select_And::select(const string& s) const {
	if (andCount == 0) {
		if (cond1->select(s)) {
			this->increment_count();
			return true;
		}
	}
	if (andCount == 1) {
		if (cond2->select(s)) {
			this->increment_count();
			this->reset_count(); // boht conds met, reset coutn and return
			return true;
		}
	}
	this->reset_count();
	return false;
}

void Select_And::increment_count() const {
	this->andCount++;
}

void Select_And::reset_count() const {
	this->andCount = 0;
}

