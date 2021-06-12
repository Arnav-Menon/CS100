#ifndef __MC_TEST_HPP__
#define __MC_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/GameQuestion.hpp"
#include "../header/type.hpp"
#include "../header/mc.hpp"

TEST(MCTEST, DisplayQ) 
{
	Type* type = new MC();
	GameQuestion* g = new Question("How many miles away is the sun?", 10);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tHow many miles away is the sun?\n");
}

TEST(MCTest, DisplayQ1) 
{
	Type* type = new MC();
	GameQuestion* g = new Question("What's the acronym for the colors of the rainbow?", 10);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tWhat's the acronym for the colors of the rainbow?\n");
}

TEST(MCTest, DisplayQ2) 
{
	Type* type = new MC();
	GameQuestion* g = new Question("Britney Spears and Justin Timberlake turned up the 2001 American Music Awards wearing outfits made out of what?", 10);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tBritney Spears and Justin Timberlake turned up the 2001 American Music Awards wearing outfits made out of what?\n");
}

TEST(MCTest, DisplayQ3) 
{
	Type* type = new MC();
	GameQuestion* g = new Question("What NBA player scored 100 points on March 2, 1962?", 10);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tWhat NBA player scored 100 points on March 2, 1962?\n");
}

TEST(MCTest, DisplayQ4) 
{
	Type* type = new MC();
	GameQuestion* g = new Question("The Weeknd released his album Starboy in what year?", 10);
	std::stringstream out;
	type->Display(g, out);
	EXPECT_EQ(out.str(), "\tThe Weeknd released his album Starboy in what year?\n");
}

TEST(MCTest, DisplayQ5)
{
        Type* type = new MC();
        GameQuestion* g = new Question("What team won the first Super Bowl?", 10);
        std::stringstream out;
        type->Display(g, out);
        EXPECT_EQ(out.str(), "\tWhat team won the first Super Bowl?\n");
}

#endif // __MC_TEST_HPP__
