#include "gtest/gtest.h"

#include "generator.h"

class GeneratorTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		empty.init(vector<int>());
	}

	Generator<int> empty;
};

TEST_F(GeneratorTest, EmptyInit) {
	EXPECT_EQ(true, empty.generate(10).empty());
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}