#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class RangeBitwiseAnd201: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(RangeBitwiseAnd201, test1){
	IntToggleString args = GetParam();
	vector<int> grid = stringToIntegerVector(args.str1);
	Solution sol;
	int res = sol.rangeBitwiseAnd(grid[0], grid[1]);
	EXPECT_EQ(res, args.int1) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, RangeBitwiseAnd201,
	::testing::Values(IntToggleString(4, "[5,7]"),
		IntToggleString(1, "[1,1]"),
		IntToggleString(4096, "[5000,5999]"),
		IntToggleString(4992, "[5000,5022]"),
		IntToggleString(0, "[5,8]"),
		IntToggleString(0, "[0,1]"),
		IntToggleString(0, "[0,2147483647]")
	));

