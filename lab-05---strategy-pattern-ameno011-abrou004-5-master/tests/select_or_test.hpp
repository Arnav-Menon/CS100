#ifndef __SELECT_OR_TEST_HPP__
#define __SELECT_OR_TEST_HPP__

#include "gtest/gtest.h"

TEST(SelectOrTest, ContainsLastNameOrMajor) {
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
	sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "Last", "Dole"), new Select_Contains(&sheet, "Major", "mathematics")));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Joe Jackson 21 mathematics \nDiane Dole 20 computer engineering \nDavid Dole 22 electrical engineering \nDominick Dole 22 communications \n");
}

TEST(SelectOrTest, ContainsAgeOrFNameAndMajor) {
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
	sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "Age", "22"), new Select_And(new Select_Contains(&sheet, "First", "D"), new Select_Contains(&sheet, "Major", "i"))));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business \nDiane Dole 20 computer engineering \nDavid Dole 22 electrical engineering \nDominick Dole 22 communications \n");
}
#endif // __SEELCT_OR_TEST_HPP__
