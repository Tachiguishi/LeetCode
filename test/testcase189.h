#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class RotateArray189: public ::testing::TestWithParam<TwoStringOneInt>{

};

TEST_P(RotateArray189, test1){
	TwoStringOneInt args = GetParam();
	Solution sol;
	vector<int> nums = stringToIntegerVector(args.str1);
	sol.rotate(nums, args.int1);
	string strRes = integerVectorToString(nums);
	EXPECT_STREQ(strRes.c_str(), args.str2.c_str()) << "input:" << args.str1 << " " << args.int1;
}

INSTANTIATE_TEST_CASE_P(leetcode, RotateArray189,
	::testing::Values(TwoStringOneInt("[1,2,3,4,5,6,7]", "[5,6,7,1,2,3,4]", 3),
		TwoStringOneInt("[-1,-100,3,99]", "[3,99,-1,-100]", 2)
	));
