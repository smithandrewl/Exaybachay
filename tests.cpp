#include "gtest/gtest.h"

#include "generator.h"
#include "textgenerator.h"

#include "util.h"
#include <iostream>

using std::string;
using std::vector;

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