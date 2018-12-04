#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class ExecelSheetColTitle168: public ::testing::TestWithParam<IntToggleString>{

};

TEST_P(ExecelSheetColTitle168, test1){
	IntToggleString args = GetParam();
	Solution sol;
	string res = sol.convertToTitle(args.int1);
	EXPECT_STREQ(res.c_str(), args.str1.c_str()) << "input:" << args.int1;
}

INSTANTIATE_TEST_CASE_P(leetcode, ExecelSheetColTitle168,
	::testing::Values(IntToggleString(1, "A"),
		IntToggleString(28, "AB"),
		IntToggleString(52, "AZ"),
		IntToggleString(701, "ZY"),
		IntToggleString(704, "AAB")
	));
