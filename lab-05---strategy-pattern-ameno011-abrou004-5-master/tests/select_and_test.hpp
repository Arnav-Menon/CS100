#ifndef __SELECT_AND_TEST_HPP__
#define __SELECT_AND_TEST_HPP__

TEST(SelectAndTest, ContainsLNameAndAge) {
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
	sheet.set_selection(
		new Select_And(
			new Select_Contains(&sheet, "Last", "Dole"),
			new Select_Contains(&sheet, "Age", "22")));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "David Dole 22 electrical engineering \nDominick Dole 22 communications \n");
}

TEST(SelectAndTest, ContainsFNameAndMajor) {
	Spreadsheet sheet;
    	sheet.set_column_names({"First","Last","Age","Major"});
    	sheet.add_row({"Amanda","Andrews","22","business"});
    	sheet.add_row({"Amanda", "Happy", "11", "business"});
	sheet.add_row({"Brian","Becker","21","computer science"});
    	sheet.add_row({"Carol","Conners","21","computer science"});
    	sheet.add_row({"Joe","Jackson","21","mathematics"});
    	sheet.add_row({"Sarah","Summers","21","computer science"});
    	sheet.add_row({"Diane","Dole","20","computer engineering"});
    	sheet.add_row({"David","Dole","22","electrical engineering"});
    	sheet.add_row({"Dominick","Dole","22","communications"});
    	sheet.add_row({"George","Genius","9","astrophysics"});
	sheet.set_selection(
		new Select_And(
			new Select_Contains(&sheet, "First", "Amanda"),
			new Select_Contains(&sheet, "Major", "business")));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business \nAmanda Happy 11 business \n");
}

TEST(SelectAndTest, ContainsNotAgeandNotLastChar) {
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
	sheet.set_selection(new Select_And(
				new Select_Not(
					new Select_Contains(&sheet, "First", "ck")),
				new Select_Not(
					new Select_Contains(&sheet, "Major", "zzzzz"))));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(), "Amanda Andrews 22 business \nBrian Becker 21 computer science \nCarol Conners 21 computer science \nJoe Jackson 21 mathematics \nSarah Summers 21 computer science \nDiane Dole 20 computer engineering \nDavid Dole 22 electrical engineering \nGeorge Genius 9 astrophysics \n");
}

#endif // __SELECT_AND_TEST_HPP__
