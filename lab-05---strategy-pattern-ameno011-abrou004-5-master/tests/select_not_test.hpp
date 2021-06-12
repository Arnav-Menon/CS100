#ifndef __SELECT_NOT_TEST_HPP__
#define __SELECT_NOT_TEST_HPP__

#include "gtest/gtest.h"

TEST(SelectNotTest, NoMajor) {
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
	sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Major", "computer science")));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business \nJoe Jackson 21 mathematics \nDiane Dole 20 computer engineering \nDavid Dole 22 electrical engineering \nDominick Dole 22 communications \nGeorge Genius 9 astrophysics \n");
}

TEST(SelectNotTest, NoLastName) {
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
	sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Last", "Dole")));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business \nBrian Becker 21 computer science \nCarol Conners 21 computer science \nJoe Jackson 21 mathematics \nSarah Summers 21 computer science \nGeorge Genius 9 astrophysics \n");
}

#endif // __SELECT_NOT_TEST_HPP__
