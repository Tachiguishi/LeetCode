#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class HappyNumber202: public ::testing::TestWithParam<BoolToggleInt>{

};

TEST_P(HappyNumber202, test1){
	BoolToggleInt args = GetParam();
	Solution sol;
	bool res = sol.isHappy(args.int1);
	if(args.vaild){
		EXPECT_TRUE(res) << "input: " << args.int1;
	}
	else{
		EXPECT_FALSE(res) << "input: " << args.int1;
	}
}

INSTANTIATE_TEST_CASE_P(leetcode, HappyNumber202,
	::testing::Values(BoolToggleInt(true, 19)
	));

