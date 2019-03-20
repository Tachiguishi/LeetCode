#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class NumberIsland200: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(NumberIsland200, test1){
	IntToggleString args = GetParam();
	vector<vector<char>> grid = stringTo2DCharVector(args.str1);
	Solution sol;
	int res = sol.numIslands(grid);
	EXPECT_EQ(res, args.int1) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, NumberIsland200,
	::testing::Values(IntToggleString(1, "[[1,1,1,1,0],[1,1,0,1,0],[1,1,0,0,0],[0,0,0,0,0]]"),
		IntToggleString(3, "[[1,1,0,0,0],[1,1,0,0,0],[0,0,1,0,0],[0,0,0,1,1]]")
	));

