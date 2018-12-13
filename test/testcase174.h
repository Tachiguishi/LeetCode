#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class DungeonGame174: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(DungeonGame174, test1){
	IntToggleString args = GetParam();
	vector<vector<int>> input;
	input = stringTo2DIntegerVector(args.str1);
	Solution sol;
	int output = sol.calculateMinimumHP(input);
	EXPECT_EQ(output, args.int1) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, DungeonGame174,
	::testing::Values(IntToggleString(7, "[[-2,-3,3].[-5,-10,1].[10,30,-5]]")
	));