#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <struct_define.h>

using namespace std;

class Solution{
public:
	// 210
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

	// 209
	int minSubArrayLen(int s, vector<int>& nums);

	// 207
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

	// 206
	ListNode* reverseList(ListNode* head);

	// 205
	bool isIsomorphic(string s, string t);

	// 204
	int countPrimes(int n);

	// 203
	ListNode* removeElements(ListNode* head, int val);

	// 202
	bool isHappy(int n);

	// 201
	int rangeBitwiseAnd(int m, int n);

	// 200
	int numIslands(vector<vector<char>>& grid);

	// 199
	vector<int> rightSideView(TreeNode* root);

	// 198
	int rob(vector<int>& nums);

	// 191
	int hammingWeight(uint32_t n);

	// 190
	uint32_t reverseBits(uint32_t n);

	// 189
	void rotate(vector<int>& nums, int k);

	// 188
	int maxProfit(int k, vector<int>& prices);

	// 187
	vector<string> findRepeatedDnaSequences(string s);

	// 186
	void reverseWords(vector<char>& str);

	// 179
	string largestNumber(vector<int>& nums);

	// 174
	int calculateMinimumHP(vector<vector<int>>& dungeon);

	// 172
	int trailingZeroes(int n);

	// 164
	int maximumGap(vector<int>& nmus);

	// 165
	int compareVersion(string version1, string version2);

	// 166
	string fractionToDecimal(int numerator, int denominator);

	// 167
	vector<int> twoSum(vector<int>& numbers, int target);

	// 168
	string convertToTitle(int n);

	// 169
	int majorityElement(vector<int>& nums);

	// 171
	int titleToNumber(string s);
};

// 173
class BSTIterator{
public:
	BSTIterator(TreeNode *root);

	/** @return whether we have a next smallest number */
	bool hasNext();

	/** @return the next smallest number */
	int next();

private:
	stack<TreeNode*> m_leftNodes;
};

// 170
class TwoSum {
public:
	/** Initialize your data structure here. */
	TwoSum() = default;

	/** Add the number to an internal data structure.. */
	void add(int number);

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value);

private:
	vector<int> m_nums;
};

// 208
class Trie{
public:
	/** Initialize your data structure here. */
	Trie();
	~Trie();

	/** Inserts a word into the trie. */
	void insert(string word);

	/** Returns if the word is in the trie. */
	bool search(string word);

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix);

private:
	bool m_bKey = false;
	char m_value = ' ';
	Trie* m_pChildren = nullptr;
};
