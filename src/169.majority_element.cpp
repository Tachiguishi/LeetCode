#include <solution.h>

int Solution::majorityElement(vector<int>& nums){
	std::map<int, int> numCount;
	for(int i : nums){
		numCount[i]++;
	}
	int res = nums[0];
	int count = 1;
	for(auto& item : numCount){
		if(item.second > count){
			count = item.second;
			res = item.first;
		}
	}
	return res;
}
