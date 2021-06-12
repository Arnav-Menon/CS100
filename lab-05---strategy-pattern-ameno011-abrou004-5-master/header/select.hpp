#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <string>
#include <iostream>
#include <vector>

#include "spreadsheet.hpp"

using namespace std;

class Select
{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select
{
protected:
    int column = 0;
    int col1 = 0;
    int col2 = 0;
    bool check = false; // if true we want to check AND condition, OR condition elsewise
    Select_Column* cond1 = nullptr;
    Select_Column* cond2 = nullptr;
public:
    Select_Column(Select_Column* one)
    {
	cond1 = one;
    }

    Select_Column(Select_Column* one, Select_Column* two)
    {	
	cond1 = one;
	cond2 = two;
    }	

    ~Select_Column() {
	delete cond1;
	delete cond2;
    }    

    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
        column = sheet->get_column_by_name(name);
    }

    int get_column() { return this->column; }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
	// Select_And
	if (cond1 != nullptr && cond2 != nullptr) {
		if (check) { // checking AND condition
			int total = 0;
			if (select(sheet->cell_data(row, col1))) total++;
			if (select(sheet->cell_data(row, col2))) total++;
			if (total == 2) return true;
			return false;
		}
		else { // checking OR condition
			if (select(sheet->cell_data(row, col1))) return true;
			if (select(sheet->cell_data(row, col2))) return true;
			return false;
		}
	}
	else if (cond1 != nullptr) {
		if (select(sheet->cell_data(row, col1))) return true;
		return false;
	}
	else {
		return select(sheet->cell_data(row, column));
	}
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};

#endif //__SELECT_HPP__
