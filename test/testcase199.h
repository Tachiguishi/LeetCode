#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class BinaryTree199: public ::testing::TestWithParam<TwoString>{

};

TEST_P(BinaryTree199, test1){
	TwoString args = GetParam();
	TreeNode* root = stringToTreeNode(args.str1);
	Solution sol;
	vector<int> num = sol.rightSideView(root);
	string res = integerVectorToString(num);
	EXPECT_STREQ(res.c_str(), args.str2.c_str()) << "input: " << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, BinaryTree199,
	::testing::Values(TwoString("[1,2,3,null,5,null,4]", "[1,3,4]")
	));

