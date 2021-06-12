#ifndef __TF_TEST_HPP__
#define __TF_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/GameQuestion.hpp"
#include "../header/question.hpp"
#include "../header/type.hpp"
#include "../header/TF.hpp"

using namespace std;

TEST(TFTest, DisplayTest1) {
    Type* type = new TF();
    GameQuestion* g = new Question("The lead singer of The Neighbourhood is Cole Sprouse.", 5);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tThe lead singer of The Neighbourhood is Cole Sprouse.\n\t\t True\n\t\t False\n");
}

TEST(TFTest, DisplayTest2) {
    Type* type = new TF();
    GameQuestion* g = new Question("Dolly Parton is Miley Cyrus God Mother.", 456);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tDolly Parton is Miley Cyrus God Mother.\n\t\t True\n\t\t False\n");
}

TEST(TFTest, DisplayTest3) {
    Type* type = new TF();
    GameQuestion* g = new Question("Electrons are larger than molecules.", 2345);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tElectrons are larger than molecules.\n\t\t True\n\t\t False\n");
}

TEST(TFTest, DisplayTest4) {
    Type* type = new TF();
    GameQuestion* g = new Question("The San Francisco 49ers have won 5 NFL championships?", 7675643);
    stringstream s;
    type->Display(g, s);
    EXPECT_EQ(s.str(), "\tThe San Francisco 49ers have won 5 NFL championships?\n\t\t True\n\t\t False\n");
}
#endif
