#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

TEST(TwoSum170, test1){
	TwoSum sol;
	sol.add(1);
	sol.add(3);
	sol.add(5);
	sol.add(2);
	sol.add(9);
	EXPECT_TRUE(sol.find(4));
	EXPECT_TRUE(sol.find(7));
	EXPECT_FALSE(sol.find(9));
	EXPECT_TRUE(sol.find(10));
	EXPECT_FALSE(sol.find(11));
}
