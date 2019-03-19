#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class HouseRobber198: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(HouseRobber198, test1){
	IntToggleString args = GetParam();
	vector<int> nums = stringToIntegerVector(args.str1);
	Solution sol;
	int res = sol.rob(nums);
	EXPECT_EQ(res, args.int1) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, HouseRobber198,
	::testing::Values(IntToggleString(4, "[1,2,3,1]"),
		IntToggleString(20, "[1,10,1,1,10]"),
		IntToggleString(12, "[2,7,9,3,1]")
	));

