#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class Isomorphic205: public ::testing::TestWithParam<TwoStringOneInt>{

};

TEST_P(Isomorphic205, test1){
	TwoStringOneInt args = GetParam();
	Solution sol;
	bool res = sol.isIsomorphic(args.str1, args.str2);
	if(args.int1){
		EXPECT_TRUE(res) << "input: " << args.str1 << " | " << args.str2;
	}
	else{
		EXPECT_FALSE(res) << "input: " << args.str1 << " | " << args.str2;
	}
}

INSTANTIATE_TEST_SUITE_P(leetcode, Isomorphic205,
	::testing::Values(TwoStringOneInt("egg", "add", 1),
		TwoStringOneInt("foo", "bar", 0),
		TwoStringOneInt("paper", "title", 1)
	));
