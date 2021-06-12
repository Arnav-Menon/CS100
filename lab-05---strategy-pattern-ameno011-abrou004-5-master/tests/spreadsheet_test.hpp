#ifndef __SPREADSHEET_TEST_HPP__
#define __SPREADSHEET_TEST_HPP__

#include "gtest/gtest.h"

#include "../src/spreadsheet.cpp"
#include "../header/select.hpp"

TEST(SpreadsheetTest, SingleRow) {
	Spreadsheet sheet;
	sheet.set_column_names({"First", "Last", "Age", "Major"});
	sheet.add_row({"Amanda", "Andrews", "22", "business"});
	std::stringstream out;
	sheet.print_selection(out);	
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business\n");
}

TEST(SpreadsheetTest, DoubleRows) {
	Spreadsheet sheet;
	sheet.set_column_names({"First", "Last", "Age", "Major"});
	sheet.add_row({"Amanda", "Andrews", "22", "business"});
	sheet.add_row({"Brian", "Becker", "21", "computer science"});
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business\nBrian Becker 21 computer science\n");
}

#endif // __SPREADSHEET_TEST_HPP__
