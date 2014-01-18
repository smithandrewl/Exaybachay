#include "gtest/gtest.h"

#include "generator.h"
#include "textgenerator.h"

#include "util.h"
#include <iostream>

using std::string;
using std::vector;

class IntGeneratorTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		empty.init(vector<int>());
		small.init({1, 4, 1, 1, 4, 5, 1, 4, 1});
	}

	Generator<int> empty;
	Generator<int> small;
};

/*
TEST_F(IntGeneratorTest, EmptyInit) {
	EXPECT_EQ(vector<int>(), empty.generate(10, std::make_pair(0, 0)));
}

TEST_F(IntGeneratorTest, GenerateZero) {
	EXPECT_EQ(vector<int>(), empty.generate(0, std::make_pair(0, 0)));
	EXPECT_EQ(vector<int>(), small.generate(0, std::make_pair(1, 4)));
}S

TEST_F(IntGeneratorTest, GenerateThree) {
	vector<int> expected = {1, 1, 4};

	EXPECT_EQ(expected, small.generate(3, std::make_pair(1, 4)));
}

TEST_F(IntGeneratorTest, GenerateSix) {
	vector<int> expected = {1, 4, 1, 1, 4, 1};

	EXPECT_EQ(expected, small.generate(6, std::make_pair(4,5)));
}

TEST(TextGenerator, EmptyInit) {
	TextGenerator textGenerator;

	textGenerator.init(vector<string>());

	EXPECT_EQ(vector<string>(), textGenerator.generate(6, std::make_pair("one", "two")));
}
*/

TEST(Split, EmptyString) {
	EXPECT_EQ(vector<string>(), split("", " "));
}

TEST(Split, OnlyDelims) {
	EXPECT_EQ(vector<string>(), split(" \t\n \n \n \t \r", " \t\n\r"));
}

TEST(Split, DelimAtStart) {
	vector<string> expected = { "first" };
	EXPECT_EQ(expected, split(" first", " "));
}

TEST(Split, DelimAtEnd) {
	vector<string> expected = { "first" };
	EXPECT_EQ(expected, split("first ", " "));
}

TEST(Split, DelimAtEnds) {
	vector<string> expected = { "first" };
	EXPECT_EQ(expected, split(" first ", " "));
}
TEST(Split, NoDelims) {
	vector<string> expected = { "first" };
	EXPECT_EQ(expected, split("first", " "));
}
TEST(Split, MultDelimsInARow) {
	vector<string> expected = { "first", "second" };
	EXPECT_EQ(expected, split("first  second", " "));
}

TEST(Split, MultDelims) {
	vector<string> expected = { "first", "second", "third" };
	EXPECT_EQ(expected, split("first\tsecond third", "\t "));
}

TEST(ToLower, EmptyString) {
	EXPECT_EQ("", toLower(""));
}

TEST(ToLower, AllLower) {
	EXPECT_EQ("abc", toLower("abc"));
}

TEST(ToLower, AllUpper) {
	EXPECT_EQ("abc", toLower("ABC"));
}

TEST(ToLower, MixedCase) {
	EXPECT_EQ("abc", toLower("aBC"));
}

TEST(ToLower, MixedCaseSpacePunc) {
	EXPECT_EQ("abc ? : d", toLower("AbC ? : d"));
}

TEST(ToAlphaNumeric, EmptyString) {
	EXPECT_EQ("", toAlphaNumeric(""));
}

TEST(ToAlphaNumeric, NoAlphaNumeric) {
	EXPECT_EQ("", toAlphaNumeric(";? \\ @"));
}

TEST(ToAlphaNumeric, OnlyAlphaNumeric) {
	EXPECT_EQ("Abj3i", toAlphaNumeric("Abj3i"));
}

TEST(ToAlphaNumeric, Mixed) {
	EXPECT_EQ("AjI3HibC", toAlphaNumeric("AjI3H:i b C"));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}