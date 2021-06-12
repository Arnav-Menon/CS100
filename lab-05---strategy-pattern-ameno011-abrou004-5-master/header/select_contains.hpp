#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include "select.hpp"

#include <string>
#include <vector>

using namespace std;

class Select_Contains: public Select_Column {
	private:
		string filter;
		int col;
		//const Spreadsheet* sheet;
	public:
		Select_Contains(const Spreadsheet*, const string&, const string&); // pass strings as const reference bc then compiler won't make a copy, which can be costly depending on size of string
		
		virtual bool select(const string&) const;	
};

#endif // __SELECT_CONTAINS_HPP__
