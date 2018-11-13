#include <gtest/gtest.h>
#include <solution.h>

TEST(MaximumGap164, Test1) {
	Solution sol;
	vector<int> nums {3,6,9,1};
	int res = sol.maximumGap(nums);
    EXPECT_EQ(res, 3);
}

TEST(MaximumGap164, Test2) {
	Solution sol;
	vector<int> nums {10};
	int res = sol.maximumGap(nums);
    EXPECT_EQ(res, 0);
}
