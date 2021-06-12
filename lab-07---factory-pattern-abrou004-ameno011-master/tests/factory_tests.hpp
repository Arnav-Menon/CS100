#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/op.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/add.hpp"
#include "../header/pow.hpp"
#include "../header/sub.hpp"
#include "../header/factory.hpp"

TEST(FactoryTest, SimpleDiv) {
	Factory test;
	char *args[] = {"garbage", "10", "/", "2"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 5);
	EXPECT_EQ(op->stringify(), "(10 / 2)");
	delete op;
}

TEST(FactoryTest, SimpleMult) {
	Factory test;
	char *args[] = {"garbage", "5", "*", "4"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 20);
	EXPECT_EQ(op->stringify(), "(5 * 4)");
	delete op;
}

TEST(FactoryTest, SimplePow) {
	Factory test;
	char *args[] = {"garbage", "5", "\\*\\*", "3"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 125);
	EXPECT_EQ(op->stringify(), "(5 ** 3)");
	delete op;
}

TEST(FactoryTest, DivMult) {
	Factory test;
	char *args[] = {"garbage", "15", "/", "3", "\\*", "7"};
	Base *op = test.parse(args, 6);
	EXPECT_DOUBLE_EQ(op->evaluate(), 35);
	EXPECT_EQ(op->stringify(), "((15 / 3) * 7)");
	delete op;
}

TEST(FactoryTest, DivPow) {
	Factory test;
	char *args[] = {"garbage", "35", "/", "5", "\\*\\*", "2"};
	Base *op = test.parse(args, 6);
	EXPECT_DOUBLE_EQ(op->evaluate(), 49);
	EXPECT_EQ(op->stringify(), "((35 / 5) ** 2)");
	delete op;
}

TEST(FactoryTest, NegMult) {
	Factory test;
	char *args[] = {"garbage", "-64", "\\*", "3"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), -192);
	EXPECT_EQ(op->stringify(), "(-64 * 3)");
	delete op;
}

TEST(FactoryTest, NegMultDiv) {
	Factory test;
	char *args[] = {"garbage", "-5", "\\*", "-16", "/", "8"};
	Base *op = test.parse(args, 6);
	EXPECT_DOUBLE_EQ(op->evaluate(), 10);
	EXPECT_EQ(op->stringify(), "((-5 * -16) / 8)");
	delete op;
}

TEST(FactoryTest, PowDecimal) {
	Factory test;
	char *args[] = {"garbage", "9", "\\*\\*", "0.5"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 3);
	EXPECT_EQ(op->stringify(), "(9 ** 0.5)");
	delete op;
}

TEST(FactoryTest, PowNegDiv) {
	Factory test;
	char *args[] = {"garbage", "4", "\\*\\*", "2", "/", "-8"};
	Base *op = test.parse(args, 6);
	EXPECT_DOUBLE_EQ(op->evaluate(), -2);
	EXPECT_EQ(op->stringify(), "((4 ** 2) / -8)");
	delete op;
}

TEST(FactoryTest, NotReallyComplexMult) {
	Factory test;
	char *args[] = {"garbage", "5", "\\*", "0", "\\*", "13526"};
	Base *op = test.parse(args, 6);
	EXPECT_DOUBLE_EQ(op->evaluate(), 0);
	EXPECT_EQ(op->stringify(), "((5 * 0) * 13526)");
	delete op;
}

TEST(FactoryTest, NotReallyComplexDivAndPow) {
	Factory test;
	char *args[] = {"garbage", "0", "/", "23456789", "\\*\\*", "87654"};
	Base *op = test.parse(args, 6);
	EXPECT_DOUBLE_EQ(op->evaluate(), 0);
	EXPECT_EQ(op->stringify(), "((0 / 23456789) ** 87654)");
	delete op;
}

TEST(FactoryTest, NotReallyComplexPow) {
	Factory test;
	char *args[] = {"garbage", "09876", "\\*\\*", "0"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 1);
	EXPECT_EQ(op->stringify(), "(9876 ** 0)");
	delete op;
}

TEST(FactoryTest, InvalidInput1) {
	Factory test;
	char *args[] = {"garbage", "5", "+", "$4"};
	Base *op = test.parse(args, 4);
	EXPECT_TRUE(op == nullptr);
	delete op;
}

TEST(FactoryTest, InvalidInput2) {
	Factory test;
	char *args[] = {"garbage", "5", "ACTUALGARBAGE", "4"};
	Base *op = test.parse(args, 4);
	EXPECT_TRUE(op == nullptr);
	delete op;
}

TEST(FactoryTest, InvalidInput) {
	Factory test;
	char *args[] = {"garbage", "-34535", "V", "4"};
	Base *op = test.parse(args, 4);
	EXPECT_TRUE(op == nullptr);
	delete op;
}


//Add tests 
TEST(FactoryTest, ZeroAddition)
{
	Factory test;
	char *args[] = {"garbage", "0", "+", "0"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 0);
	EXPECT_EQ(op->stringify(), "(0 + 0)");
	delete op;
}

TEST(FactoryTest, ZeroAndNumberAddition)
{
        Factory test;
        char *args[] = {"garbage", "0", "+", "23"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), 23);
	EXPECT_EQ(op->stringify(), "(0 + 23)");
	delete op;
}

TEST(FactoryTest, SimpleAddition)
{
	Factory test;
	char *args[] = {"garbage", "2", "+", "1"};
	Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 3);
	EXPECT_EQ(op->stringify(), "(2 + 1)");
	delete op;
}

TEST(FactoryTest, MultipleAddition)
{
	Factory test;
	char *args[] = {"garbage", "1", "+", "2", "+", "3", "+", "4", "+", "5"};
	Base *op = test.parse(args, 10);
	EXPECT_DOUBLE_EQ(op->evaluate(), 15);
	EXPECT_EQ(op->stringify(), "((((1 + 2) + 3) + 4) + 5)");
	delete op;
}

TEST(FactoryTest, BigNumberAddition)
{
	Factory test;
	char *args[] = {"garbage", "230716", "+", "149094"};
	Base *op = test.parse(args,4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 379810);
	EXPECT_EQ(op->stringify(), "(230716 + 149094)");
	delete op;
}

TEST(FactoryTest, NegativeBigNumberAddition)
{
        Factory test;
        char *args[] = {"garbage", "-230716", "+", "-149094"};
        Base *op = test.parse(args,4);
        EXPECT_DOUBLE_EQ(op->evaluate(), -379810);
	EXPECT_EQ(op->stringify(), "(-230716 + -149094)");
	delete op;
}

TEST(FactoryTest, MultipleNegativeAddition2)
{
        Factory test;
        char *args[] = {"garbage", "-1", "+", "-2", "+", "-3", "+", "-4", "+", "-5"};
        Base *op = test.parse(args, 10);
        EXPECT_DOUBLE_EQ(op->evaluate(), -15);
	EXPECT_EQ(op->stringify(), "((((-1 + -2) + -3) + -4) + -5)");
	delete op;
}

TEST(FactoryTest, SimpleNegativeAddition1)
{
        Factory test;
        char *args[] = {"garbage", "-3", "+", "-7"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), -10);
	EXPECT_EQ(op->stringify(), "(-3 + -7)");
	delete op;
}

TEST(FactoryTest, NegativeZeroAndNumberAddition)
{
        Factory test;
        char *args[] = {"garbage", "0", "+", "-27"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), -27);
	EXPECT_EQ(op->stringify(), "(0 + -27)");
	delete op;
}

TEST(FactoryTest, InvalidAddition1)
{
        Factory test;
        char *args[] = {"garbage", "YOLO", "+", "CS"};
        Base *op = test.parse(args, 4);
        EXPECT_TRUE(op == nullptr);
	delete op;
}



//Sub
TEST(FactoryTest, ZeroSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "0", "-", "0"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), 0);
	EXPECT_EQ(op->stringify(), "(0 - 0)");
	delete op;
}

TEST(FactoryTest, ZeroAndNumberSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "0", "-", "14"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), -14);
	EXPECT_EQ(op->stringify(), "(0 - 14)");
	delete op;
}

TEST(FactoryTest, NumberandZeroSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "14", "-", "0"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), 14);
	EXPECT_EQ(op->stringify(), "(14 - 0)");
	delete op;
}


TEST(FactoryTest, SimpleSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "11", "-", "1"};
        Base *op = test.parse(args, 4);
        EXPECT_DOUBLE_EQ(op->evaluate(), 10);
	EXPECT_EQ(op->stringify(), "(11 - 1)");
	delete op;
}

TEST(FactoryTest, MultipleSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "15", "-", "1", "-", "2", "-", "3", "-", "4"};
        Base *op = test.parse(args, 10);
        EXPECT_DOUBLE_EQ(op->evaluate(), 5);
	EXPECT_EQ(op->stringify(), "((((15 - 1) - 2) - 3) - 4)");
	delete op;
}

TEST(FactoryTest, BigNumberSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "230716", "-", "149094"};
        Base *op = test.parse(args,4);
        EXPECT_DOUBLE_EQ(op->evaluate(), 81622);
	EXPECT_EQ(op->stringify(), "(230716 - 149094)");
	delete op;
}

TEST(FactoryTest, NegativeBigNumberSubtraction)
{
        Factory test;
        char *args[] = {"garbage", "-230716", "-", "-149094"};
        Base *op = test.parse(args,4);
        EXPECT_DOUBLE_EQ(op->evaluate(), -81622);
	EXPECT_EQ(op->stringify(), "(-230716 - -149094)");
	delete op;
}

TEST(FactoryTest, MultipleNegativeAddition1)
{
        Factory test;
        char *args[] = {"garbage", "-2", "-", "-4", "-", "-6", "-", "-8", "-", "-10"};
        Base *op = test.parse(args, 10);
        EXPECT_DOUBLE_EQ(op->evaluate(), 26);
	EXPECT_EQ(op->stringify(), "((((-2 - -4) - -6) - -8) - -10)");
	delete op;
}

TEST(FactoryTest, SimpleNegativeAddition)
{
        Factory test;
        char *args[] = {"garbage", "-3", "-", "-7"};
        Base *op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 4);
	EXPECT_EQ(op->stringify(), "(-3 - -7)");
	delete op;
}

TEST(FactoryTest, InvalidAddition)
{
        Factory test;
        char *args[] = {"garbage", "BIG", "-", "SMALL"};
        Base *op = test.parse(args, 4);
        EXPECT_TRUE(op == nullptr);
	delete op;
}


//Combo
TEST(FactoryTest, ZeroCombo)
{
        Factory test;
        char *args[] = {"garbage", "0", "+", "0", "-", "0"};
        Base *op = test.parse(args, 6);
        EXPECT_DOUBLE_EQ(op->evaluate(),0);
	EXPECT_EQ(op->stringify(), "((0 + 0) - 0)");
	delete op;
}

TEST(FactoryTest, ZeroAndNumberCombo)
{
        Factory test;
        char *args[] = {"garbage", "0", "+", "4", "-", "14"};
        Base *op = test.parse(args, 6);
        EXPECT_DOUBLE_EQ(op->evaluate(), -10);
	EXPECT_EQ(op->stringify(), "((0 + 4) - 14)");
	delete op;
}

TEST(FactoryTest, NumberandZeroCombo)
{
        Factory test;
        char *args[] = {"garbage", "14", "-", "4", "+", "0"};
        Base *op = test.parse(args, 6);
        EXPECT_DOUBLE_EQ(op->evaluate(),10);
	EXPECT_EQ(op->stringify(), "((14 - 4) + 0)");
	delete op;
}


TEST(FactoryTest, SimpleCombo)
{
        Factory test;
        char *args[] = {"garbage", "6", "+", "11", "-", "1"};
        Base *op = test.parse(args, 6);
        EXPECT_DOUBLE_EQ(op->evaluate(), 16);
	EXPECT_EQ(op->stringify(), "((6 + 11) - 1)");
	delete op;
}

TEST(FactoryTest, MultipleCombo)
{
        Factory test;
        char *args[] = {"garbage", "15", "-", "1", "+", "2", "-", "3", "+", "4"};
        Base *op = test.parse(args, 10);
        EXPECT_DOUBLE_EQ(op->evaluate(), 17);
	EXPECT_EQ(op->stringify(), "((((15 - 1) + 2) - 3) + 4)");
	delete op;
}

TEST(FactoryTest, BigNumberCombo)
{
        Factory test;
        char *args[] = {"garbage", "716", "-", "1490", "+", "1000"};
        Base *op = test.parse(args,6);
        EXPECT_DOUBLE_EQ(op->evaluate(), 226);
	EXPECT_EQ(op->stringify(), "((716 - 1490) + 1000)");
	delete op;
}

TEST(FactoryTest, MultipleNegativeCombo)
{
        Factory test;
        char *args[] = {"garbage", "-2", "+", "-4", "-", "-6", "+", "-8", "-", "-10"};
        Base *op = test.parse(args, 10);
        EXPECT_DOUBLE_EQ(op->evaluate(), 2);
	EXPECT_EQ(op->stringify(), "((((-2 + -4) - -6) + -8) - -10)");
	delete op;
}

TEST(FactoryTest, SimpleNegativeCombo)
{
        Factory test;
        char *args[] = {"garbage", "-3", "-", "-7", "+", "-1"};
        Base *op = test.parse(args, 6);
        EXPECT_DOUBLE_EQ(op->evaluate(), 3);
	EXPECT_EQ(op->stringify(), "((-3 - -7) + -1)");
	delete op;
}

TEST(FactoryTest, InvalidCombo)
{
        Factory test;
        char *args[] = {"garbage", "Bacon", "-", "eggs", "+", "Pancakes"};
        Base *op = test.parse(args, 6);
        EXPECT_TRUE(op == nullptr);
	delete op;
}

#endif // __FACTORY_TEST_HPP__
