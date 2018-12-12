#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

class BSTIterator173: public ::testing::TestWithParam<TwoString>{

};

TEST_P(BSTIterator173, test1){
	TwoString args = GetParam();
	TreeNode* root = stringToTreeNode(args.str1);
	BSTIterator iter(root);
	vector<int> res;
	while(iter.hasNext()) res.push_back(iter.next());
	string strRes = integerVectorToString(res);
	EXPECT_STREQ(strRes.c_str(), args.str2.c_str()) << "input:" << args.str1;
}

INSTANTIATE_TEST_CASE_P(leetcode, BSTIterator173,
	::testing::Values(TwoString("[4,2,6,1,3,5,7]", "[1,2,3,4,5,6,7]"),
		TwoString("[4,2,6,1,null,5,7]", "[1,2,4,5,6,7]"),
		TwoString("[3,2,4,1,null,null,5]", "[1,2,3,4,5]")
	));