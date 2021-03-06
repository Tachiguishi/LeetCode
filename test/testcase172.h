#include <gtest/gtest.h>
#include <solution.h>

TEST(FactorialTrailingZeroes172, test1){
	Solution sol;
	vector<int> input = {3, 5, 9, 10, 20, 50, 100, 134, 142, 999, 9999, 99999};
	vector<int> output = {0, 1, 1, 2, 4, 12, 24, 32, 34, 246, 2495, 24994};
	for(size_t i = 0; i < input.size(); ++i){
		EXPECT_EQ(sol.trailingZeroes(input[i]), output[i]) << "input: " << input[i];
	}
}
