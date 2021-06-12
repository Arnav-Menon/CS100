#include "../header/select_contains.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

Select_Contains::Select_Contains(const Spreadsheet* sheet, const string& c, const string& f) : Select_Column(sheet, c) 
{ // pass strings as const reference bc then compiler won't make a copy, which can be costly depending on size of string
	column = sheet->get_column_by_name(c);
	filter = f;
}

bool Select_Contains::select(const string& s) const {
	if (s == filter) { // if filter member variable is in string passed in, return true
		return true;
	}
	else if (s.find(filter) != std::string::npos) { // find substring
		return true;
	}
	return false;	
}
