#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class RepeatedDNA187: public ::testing::TestWithParam<TwoString>{

};

TEST_P(RepeatedDNA187, test1){
	TwoString args = GetParam();
	Solution sol;
	vector<string> res = sol.findRepeatedDnaSequences(args.str1);
	string strRes = stringVectorToString(res);
	EXPECT_STREQ(strRes.c_str(), args.str2.c_str()) << "input:" << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, RepeatedDNA187,
	::testing::Values(TwoString("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", "[AAAAACCCCC,CCCCCAAAAA]"),
		TwoString("AAAAAAAAAAA", "[AAAAAAAAAA]"),
		TwoString("GAGAGAGAGAGAG", "[GAGAGAGAGA,AGAGAGAGAG]"),
		TwoString("", "[]")
	));
