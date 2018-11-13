#include <gtest/gtest.h>
#include <solution.h>

struct TwoStringToInt{
	string str1;
	string str2;
	int res;
	TwoStringToInt(const char* s1, const char* s2, int i):
	str1(s1), str2(s2), res(i){}
};

class CompareVersion165: public ::testing::TestWithParam<TwoStringToInt>{

};

TEST_P(CompareVersion165, test1){
	TwoStringToInt args = GetParam();
	Solution sol;
	int res = sol.compareVersion(args.str1, args.str2);
	EXPECT_EQ(res, args.res) << args.str1 << "::" << args.str2 << ">>" << res;
}

INSTANTIATE_TEST_CASE_P(leetcode, CompareVersion165,
	::testing::Values(TwoStringToInt("0.1", "1.1", -1),
		TwoStringToInt("1.0.1", "1", 1),
		TwoStringToInt("7.5.2.4", "7.5.3", -1),
		TwoStringToInt("1.2.3", "1.2.3", 0),
		TwoStringToInt("1.10.1", "1.2.1", 1)));
