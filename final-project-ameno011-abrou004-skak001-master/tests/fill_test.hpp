#ifndef __FILL_TEST_HPP__
#define __FILL_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/GameQuestion.hpp"
#include "../header/type.hpp"
#include "../header/fill.hpp"

TEST(FillTest, DisplayQ) {
	Type* type = new Fill();
	GameQuestion* g = new Question("How big is the sun?", 5);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tHow big is the sun?\n");
}

TEST(FillTest, DisplayQ1) {
	Type* type = new Fill();
	GameQuestion* g = new Question("The ___ is the nearest star to Earth.", 5);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tThe ___ is the nearest star to Earth.\n");
}

TEST(FillTest, DisplayQ2) {
	Type* type = new Fill();
	GameQuestion* g = new Question("Michael Jordan is the ___.", 5);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tMichael Jordan is the ___.\n");
}

TEST(FillTest, DisplayQ3) {
	Type* type = new Fill();
	GameQuestion* g = new Question("Justin Timberlake was a part of the band ___.", 5);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tJustin Timberlake was a part of the band ___.\n");
}

TEST(FillTest, DisplayQ4) {
	Type* type = new Fill();
	GameQuestion* g = new Question("Dwight Howard deserves to be in the Hall of ___.", 5);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tDwight Howard deserves to be in the Hall of ___.\n");
}
#endif // __FILL_TEST_HPP__
