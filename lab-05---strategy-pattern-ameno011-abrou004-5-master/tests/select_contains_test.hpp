#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"

#include "../src/select_contains.cpp"
#include "../header/select.hpp"
#include "../src/select_and.cpp"
#include "../header/select_or.hpp"
#include "../src/select_not.cpp"

TEST(SelectContainsTest, ContainsFirstName) {
	Spreadsheet sheet;
	sheet.set_column_names({"First", "Last", "Age", "Major"});
	sheet.add_row({"Amanda", "Andrews", "22", "business"});
	sheet.add_row({"Brian", "Becker", "21", "computer science"});
	sheet.set_selection(new Select_Contains(&sheet, "First", "Amanda"));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business \n");
}

TEST(SelectContainsTest, ContainsLastName) {
	Spreadsheet sheet;
	sheet.set_column_names({"First", "Last", "Age", "Major"});
	sheet.add_row({"Amanda", "Andrews", "22", "business"});
	sheet.add_row({"Brian", "Becker", "21", "computer science"});
	sheet.set_selection(new Select_Contains(&sheet, "Last", "Becker"));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Brian Becker 21 computer science \n");
}

TEST(SelectContainsTest, ContainsAge) {
	Spreadsheet sheet;
    	sheet.set_column_names({"First","Last","Age","Major"});
    	sheet.add_row({"Amanda","Andrews","22","business"});
    	sheet.add_row({"Brian","Becker","21","computer science"});
    	sheet.add_row({"Carol","Conners","21","computer science"});
    	sheet.add_row({"Joe","Jackson","21","mathematics"});
    	sheet.add_row({"Sarah","Summers","21","computer science"});
    	sheet.add_row({"Diane","Dole","20","computer engineering"});
    	sheet.add_row({"David","Dole","22","electrical engineering"});
    	sheet.add_row({"Dominick","Dole","22","communications"});
    	sheet.add_row({"George","Genius","9","astrophysics"});
	sheet.set_selection(new Select_Contains(&sheet, "Age", "21"));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Brian Becker 21 computer science \nCarol Conners 21 computer science \nJoe Jackson 21 mathematics \nSarah Summers 21 computer science \n");
}

TEST(SelectContainsTest, ContainsMajor) {
	Spreadsheet sheet;
    	sheet.set_column_names({"First","Last","Age","Major"});
    	sheet.add_row({"Amanda","Andrews","22","business"});
    	sheet.add_row({"Brian","Becker","21","computer science"});
    	sheet.add_row({"Carol","Conners","21","computer science"});
    	sheet.add_row({"Joe","Jackson","21","mathematics"});
    	sheet.add_row({"Sarah","Summers","21","computer science"});
    	sheet.add_row({"Diane","Dole","20","computer engineering"});
    	sheet.add_row({"David","Dole","22","electrical engineering"});
    	sheet.add_row({"Dominick","Dole","22","communications"});
    	sheet.add_row({"George","Genius","9","astrophysics"});
	sheet.set_selection(new Select_Contains(&sheet, "Major", "astrophysics"));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "George Genius 9 astrophysics \n");
}

TEST(SelectContainsTest, ContainsSubstring) {
	Spreadsheet sheet;
    	sheet.set_column_names({"First","Last","Age","Major"});
    	sheet.add_row({"Amanda","Andrews","22","business"});
    	sheet.add_row({"Brian","Becker","21","computer science"});
    	sheet.add_row({"Carol","Conners","21","computer science"});
    	sheet.add_row({"Joe","Jackson","21","mathematics"});
    	sheet.add_row({"Sarah","Summers","21","computer science"});
    	sheet.add_row({"Diane","Dole","20","computer engineering"});
    	sheet.add_row({"David","Dole","22","electrical engineering"});
    	sheet.add_row({"Dominick","Dole","22","communications"});
    	sheet.add_row({"George","Genius","9","astrophysics"});
	sheet.set_selection(new Select_Contains(&sheet, "Major", "mm"));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Dominick Dole 22 communications \n");
}

#endif // __SELECT_CONTAINS_TEST_HPP__
