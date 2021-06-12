#ifndef __GAME_TEST_HPP__
#define __GAME_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/game.hpp"
#include "../header/type.hpp"

TEST(GameTest, LoadAllGameQuestions) {
	Game g;
	string topic = "sports";
	g.LoadQuestions(topic, "fill");
	g.LoadQuestions(topic, "tf");
	g.LoadQuestions(topic, "mc");
	// expect 6 game questions
	EXPECT_DOUBLE_EQ(g.HowManyQuestions(), 6);
}

TEST(GameTest, LoadFourGameQuestions) {
	Game g;
	string topic = "sports";
	g.LoadQuestions(topic, "fill");
	g.LoadQuestions(topic, "tf");
	// expect 4 game questions
	EXPECT_DOUBLE_EQ(g.HowManyQuestions(), 4);
}

TEST(GameTest, LoadTwoGameQuestions) {
	Game g;
	string topic = "sports";
	g.LoadQuestions(topic, "fill");
	// expect 2 game questions
	EXPECT_DOUBLE_EQ(g.HowManyQuestions(), 2);
}

#endif // __GAME_TEST_HPP__
