#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class BuySellStock188: public ::testing::TestWithParam<OneStringTwoInt>{

};

TEST_P(BuySellStock188, test1){
	OneStringTwoInt args = GetParam();
	Solution sol;
	vector<int> vParam = stringToIntegerVector(args.str1);
	int res = sol.maxProfit(args.int1, vParam);
	EXPECT_EQ(res, args.int2) << "input:" << args.int1 << " " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, BuySellStock188,
	::testing::Values(OneStringTwoInt("[2,4,1]", 2, 2),
		OneStringTwoInt("[3,2,6,5,0,3]", 2, 7)
	));
