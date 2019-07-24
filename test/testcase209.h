#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class MinSubArrayLen209: public ::testing::TestWithParam<OneStringTwoInt>{

};

TEST_P(MinSubArrayLen209, test1){
	OneStringTwoInt args = GetParam();
	Solution sol;
	vector<int> nums = stringToIntegerVector(args.str1);
	int res = sol.minSubArrayLen(args.int1, nums);
	EXPECT_EQ(res, args.int2) << "input: " << args.int1 << ", " << args.str1;
}

INSTANTIATE_TEST_SUITE_P(leetcode, MinSubArrayLen209,
	::testing::Values(OneStringTwoInt("[2,3,1,2,4,3]", 7, 2)
	));
