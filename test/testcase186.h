#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class BSTIterator173: public ::testing::TestWithParam<TwoString>{

};

TEST_P(BSTIterator173, test1){
	TwoString args = GetParam();
	vector<char> param = stringToCharVector(args.str1);
	Solution sol;
	sol.reverseWords(param);
	string strRes = charVectorToString(param);
	EXPECT_STREQ(strRes.c_str(), args.str2.c_str()) << "input:" << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, BSTIterator173,
	::testing::Values(TwoString("[t,h,e, ,s,k,y, ,i,s, ,b,l,u,e]", "[b,l,u,e, ,i,s, ,s,k,y, ,t,h,e]")
	));