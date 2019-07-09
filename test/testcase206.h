#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class ReverseLinkList206: public ::testing::TestWithParam<TwoString>{

};

TEST_P(ReverseLinkList206, test1){
	TwoString args = GetParam();
	Solution sol;
	ListNode* param = stringToListNode(args.str1);
	ListNode* res = sol.reverseList(param);
	string resStr = listNodeToString(res);
	EXPECT_STREQ(resStr.c_str(), args.str2.c_str()) << "input: " << args.str1;
}

INSTANTIATE_TEST_SUITE_P(leetcode, ReverseLinkList206,
	::testing::Values(TwoString("[1,2,3,4,5]", "[5,4,3,2,1]"),
		TwoString("[1,2]", "[2,1]"),
		TwoString("[1]", "[1]")
	));
