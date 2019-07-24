#include <gtest/gtest.h>
#include <solution.h>
#include "transform.h"

using namespace leetcode;

TEST(Trie208, test1){
	Trie trie;
	trie.insert("apple");
	EXPECT_TRUE(trie.search("apple"));
	EXPECT_FALSE(trie.search("app"));
	EXPECT_TRUE(trie.startsWith("app"));
	trie.insert("app");   
	EXPECT_TRUE(trie.search("app"));
}
