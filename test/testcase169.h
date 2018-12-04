#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class MajorityElement169: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(MajorityElement169, test1){
	IntToggleString args = GetParam();
	Solution sol;
	vector<int> nums = stringToIntegerVector(args.str1);
	int res = sol.majorityElement(nums);
	EXPECT_EQ(res, args.int1) << "input:" << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, MajorityElement169,
	::testing::Values(IntToggleString(3, "[3,2,3]"),
		IntToggleString(2, "[2,2,1,1,1,2,2]")
	));
