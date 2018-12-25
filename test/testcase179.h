#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class LargestNumber179: public ::testing::TestWithParam<TwoString>{

};

TEST_P(LargestNumber179, test1){
	TwoString args = GetParam();
	vector<int> input;
	input = stringToIntegerVector(args.str1);
	Solution sol;
	string strRes = sol.largestNumber(input);
	EXPECT_STREQ(strRes.c_str(), args.str2.c_str()) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, LargestNumber179,
	::testing::Values(TwoString("[10,2]", "210"),
		TwoString("[1,2,3,4,5,6,7,8,9,0]", "9876543210"),
		TwoString("[0,0]", "0"),
		TwoString("[824,938,1399,5607,6973,5703,9609,4398,8247]", "9609938824824769735703560743981399"),
		TwoString("[3,30,34,9,5]", "9534330")
	));
