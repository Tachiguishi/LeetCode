#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

TEST(Trie208, test1){
	WordDictionary sol;
	sol.addWord("bad");
	sol.addWord("dad");
	sol.addWord("mad");
	EXPECT_FALSE(sol.search("pad"));
	EXPECT_TRUE(sol.search("bad"));
	EXPECT_TRUE(sol.search(".ad"));
	EXPECT_TRUE(sol.search("b.."));
}
