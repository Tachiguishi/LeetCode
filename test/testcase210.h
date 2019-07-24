#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class CourseSchedule210: public ::testing::TestWithParam<TwoStringOneInt>{

};

TEST_P(CourseSchedule210, test1){
	TwoStringOneInt args = GetParam();
	Solution sol;
	vector<vector<int>> prerequisites = stringTo2DIntegerVector(args.str1);
	vector<int> res = sol.findOrder(args.int1, prerequisites);
	string resStr = integerVectorToString(res);
	EXPECT_STREQ(resStr.c_str(), args.str2.c_str()) << args.int1 << ", " << args.str1;
}

INSTANTIATE_TEST_SUITE_P(leetcode, CourseSchedule210,
	::testing::Values(TwoStringOneInt("[[1,0]] ", "[0,1]", 2),
		TwoStringOneInt("[[1,0].[2,0].[3,1].[3,2]]", "[0,1,2,3]", 4)
	));
