#ifndef __OPTION_TEST_HPP__
#define __OPTION_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/option.hpp"

TEST(OptionTest, TestCorrectAnswerTrue) {
  Option o("TestOption", true);
  EXPECT_EQ(o.CorrectAnswer(), true);
}

TEST(OptionTest, TestCorrectAnswerFalse) {
  Option o("TestOption", false);
  EXPECT_EQ(o.CorrectAnswer(), false);
}

TEST(OptionTest, TestOptionStringTrue) {
  Option o("TestOption", true);
  EXPECT_EQ(o.GetAnswer(), "TestOption");
}

TEST(OptionTest, TestOptionStringFalse) {
  Option o("TestOption", false);
  EXPECT_NE(o.GetAnswer(), "Wrong");
}

#endif
