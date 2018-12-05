#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
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
