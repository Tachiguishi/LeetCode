#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class RemoveListElement203: public ::testing::TestWithParam<TwoStringOneInt>{

};

TEST_P(RemoveListElement203, test1){
	TwoStringOneInt args = GetParam();
	ListNode* param = stringToListNode(args.str1);
	Solution sol;
	ListNode* res = sol.removeElements(param, args.int1);
	string strRes = listNodeToString(res);
	EXPECT_STREQ(strRes.c_str(), args.str2.c_str()) << "input: " << args.str1 << " ==> " << args.int1;
}

INSTANTIATE_TEST_CASE_P(leetcode, RemoveListElement203,
	::testing::Values(TwoStringOneInt("[1,2,6,3,4,5,6]", "[1,2,3,4,5]", 6)
	));

