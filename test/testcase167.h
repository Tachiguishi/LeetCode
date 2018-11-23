#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class TwoSum167: public ::testing::TestWithParam<TwoStringOneInt>{

};

TEST_P(TwoSum167, test1){
	TwoStringOneInt args = GetParam();
	vector<int> input = stringToIntegerVector(args.str1);
	Solution sol;
	vector<int> res = sol.twoSum(input, args.int1);
	string strResult = integerVectorToString(res);
	EXPECT_STREQ(strResult.c_str(), args.str2.c_str()) << args.str1 << ">>" << args.int1;
}

INSTANTIATE_TEST_CASE_P(leetcode, TwoSum167,
	::testing::Values(TwoStringOneInt("[2,7,11,15]", "[1,2]", 9)
	));
