#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class CourseSchedule207: public ::testing::TestWithParam<OneStringTwoInt>{

};

TEST_P(CourseSchedule207, test1){
	OneStringTwoInt args = GetParam();
	Solution sol;
	vector<vector<int>> param = stringTo2DIntegerVector(args.str1);
	bool res = sol.canFinish(args.int1, param);
	int resInt = res ? 1 : 0;
	EXPECT_EQ(resInt, args.int2) << "input: " << args.str1 << " | " << args.int1;
}

INSTANTIATE_TEST_SUITE_P(leetcode, CourseSchedule207,
	::testing::Values(OneStringTwoInt("[[1,0]]", 2, 1),
		OneStringTwoInt("[[1,0].[0,1]]", 2, 0)
	));
