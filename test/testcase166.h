#include <gtest/gtest.h>
#include <solution.h>
#include <climits>

struct TwoIntToString{
	int val1;
	int val2;
	string res;
	TwoIntToString(int i, int j, const char* str):
	val1(i), val2(j), res(str){}
};

class FractionToDecimal166: public ::testing::TestWithParam<TwoIntToString>{

};

TEST_P(FractionToDecimal166, test1){
	TwoIntToString args = GetParam();
	Solution sol;
	string res = sol.fractionToDecimal(args.val1, args.val2);
	EXPECT_STREQ(res.c_str(), args.res.c_str()) << args.val1 << "/" << args.val2 << " ==> " << (double)args.val1/args.val2;
}

INSTANTIATE_TEST_CASE_P(leetcode, FractionToDecimal166,
	::testing::Values(TwoIntToString(1,2,"0.5"),
	TwoIntToString(-2147483648, 1, "-2147483648"),
	TwoIntToString(-1, -2147483648, "0.0000000004656612873077392578125"),
	TwoIntToString(2,1,"2"),
	TwoIntToString(2,3,"0.(6)"),
	TwoIntToString(1,8,"0.125"),
	TwoIntToString(67,6,"11.1(6)"),
	TwoIntToString(1,0,"NaN"),
	TwoIntToString(-2,1,"-2"),
	TwoIntToString(2,-3,"-0.(6)"),
	TwoIntToString(-2,3,"-0.(6)"),
	TwoIntToString(-9,8,"-1.125"),
	TwoIntToString(9,-8,"-1.125"),
	TwoIntToString(67,-6,"-11.1(6)"),
	TwoIntToString(-1,0,"NaN"),
	TwoIntToString(378261,3, "126087"),
	TwoIntToString(INT_MIN, -1,"2147483648")
	));
