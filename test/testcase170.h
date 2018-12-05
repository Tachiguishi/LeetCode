#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

TEST(TwoSum170, test1){
	TwoSum sol;
	sol.add(1);
	sol.add(3);
	sol.add(5);
	EXPECT_TRUE(sol.find(4));
	EXPECT_FALSE(sol.find(7));
}

TEST(TwoSum170, test2){
	TwoSum sol;
	sol.add(3);
	sol.add(1);
	sol.add(2);
	EXPECT_TRUE(sol.find(3));
	EXPECT_FALSE(sol.find(6));
}
