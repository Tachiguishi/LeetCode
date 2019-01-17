#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class ReverseBits190: public ::testing::TestWithParam<TwoString>{

};

TEST_P(ReverseBits190, test1){
	TwoString args = GetParam();
	uint32_t input = stringBitsToInteger(args.str1);
	Solution sol;
	uint32_t output = sol.reverseBits(input);
	string res = IntegerToStringBits(output);
	EXPECT_STREQ(res.c_str(), args.str2.c_str()) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, ReverseBits190,
	::testing::Values(TwoString("00000010100101000001111010011100", "00111001011110000010100101000000"),
		TwoString("11111111111111111111111111111101", "10111111111111111111111111111111")
	));
