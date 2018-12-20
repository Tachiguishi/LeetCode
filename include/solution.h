#include <vector>
#include <string>
#include <map>
#include <stack>
#include <struct_define.h>

using namespace std;

class Solution{
public:
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
