#include "../header/spreadsheet.hpp"
#include "../header/select_contains.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Spreadsheet::~Spreadsheet()
{
    delete select;
}

void Spreadsheet::set_selection(Select* new_select)
{
    delete select;
    select = new_select;
}

void Spreadsheet::clear()
{
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    for (int i = 0; i < names.size() - 1; i++) {
	for (int j = i + 1; j < names.size(); j++) {
	    if (names.at(i) == names.at(j))
		throw std::invalid_argument("Columns can't have the same name");	
	}
    }
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    throw std::invalid_argument("Column does not exist");
    return -1;
}

void Spreadsheet::print_selection(std::ostream& out) const {
	bool addEndline = false;	

	if (select == nullptr) { // no "constraints", print everything
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.at(i).size() - 1; j++) {
				out << data.at(i).at(j) << " ";
			}
			out << data.at(i).at(data.at(i).size() - 1) << endl;
		}
	}
	else {
		for (int i = 0; i < data.size(); i++) { // traverse rows
			for (int j = 0; j < data.at(i).size(); j++) { // traverse columns
				if (select->select(this, i)) {
					out << data.at(i).at(j) << " ";
					addEndline = true;
				}
			}
			if (addEndline) { 
				addEndline = false;
				out << endl; // only add endl if needed
			}
		}
	}
}

