#include "gtest/gtest.h"

#include "generator.h"
#include <iostream>

using std::string;

class IntGeneratorTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		empty.init(vector<int>());
		small.init({1, 4, 1, 1, 4, 5, 1, 4, 1});
	}

	Generator<int> empty;
	Generator<int> small;
};

TEST_F(IntGeneratorTest, EmptyInit) {
	EXPECT_EQ(vector<int>(), empty.generate(10, std::make_pair(0, 0)));
}

TEST_F(IntGeneratorTest, GenerateZero) {
	EXPECT_EQ(vector<int>(), empty.generate(0, std::make_pair(0, 0)));
	EXPECT_EQ(vector<int>(), small.generate(0, std::make_pair(1, 4)));
}

TEST_F(IntGeneratorTest, GenerateThree) {
	vector<int> expected = {1, 1, 4};

	EXPECT_EQ(expected, small.generate(3, std::make_pair(1, 4)));
}

TEST_F(IntGeneratorTest, GenerateSix) {
	vector<int> expected = {1, 4, 1, 1, 4, 1};

	EXPECT_EQ(expected, small.generate(6, std::make_pair(4,5)));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}