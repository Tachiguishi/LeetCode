#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class NumberofBits191: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(NumberofBits191, test1){
	IntToggleString args = GetParam();
	uint32_t input = stringBitsToInteger(args.str1);
	Solution sol;
	int res = sol.hammingWeight(input);
	EXPECT_EQ(res, args.int1) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, NumberofBits191,
	::testing::Values(IntToggleString(3, "00000000000000000000000000001011"),
		IntToggleString(1, "00000000000000000000000010000000"),
		IntToggleString(31, "11111111111111111111111111111101")
	));
