#include <solution.h>

vector<int> Solution::twoSum(vector<int>& numbers, int target){
	int left = 1;
	int right = numbers.size();
	while(left < right){
		int sum = numbers[left - 1] + numbers[right - 1];
		if(sum == target){
			break;
		}
		else if(sum < target){
			++left;
		}
		else{
			--right;
		}
	}
	vector<int> res;
	res.push_back(left);
	res.push_back(right);
	return res;
}
