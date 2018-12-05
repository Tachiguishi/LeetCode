#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class ExecelSheetColNumber171: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(ExecelSheetColNumber171, test1){
	IntToggleString args = GetParam();
	Solution sol;
	int res = sol.titleToNumber(args.str1);
	EXPECT_EQ(res, args.int1) << "input:" << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, ExecelSheetColNumber171,
	::testing::Values(IntToggleString(1, "A"),
		IntToggleString(28, "AB"),
		IntToggleString(52, "AZ"),
		IntToggleString(701, "ZY"),
		IntToggleString(704, "AAB")
	));
