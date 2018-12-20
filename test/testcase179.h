#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class LargestNumber179: public ::testing::TestWithParam<TwoString>{

};

TEST_P(LargestNumber179, test1){
	TwoString args = GetParam();
	vector<int> input;
	input = stringToIntegerVector(args.str1);
	Solution sol;
	string output = sol.largestNumber(input);
	EXPECT_EQ(output, args.str2) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, LargestNumber179,
	::testing::Values(TwoString("[10,2]", "210"),
		TwoString("[3,30,34,5,9]", "9534330")
	));
