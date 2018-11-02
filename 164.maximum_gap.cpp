#include "solution.h"

int Solution::maximumGap(vector<int>& nums){
	if(nums.size() < 2){
		return 0;
	}

	int minNum = nums[0];
	int maxNum = nums[0];
	for(int& i : nums){
		minNum = min(minNum, i);
		maxNum = max(maxNum, i);
	}

	int len = (maxNum - minNum)/nums.size() + 1;
	int bucketSize = (maxNum - minNum)/len + 1;
	vector<vector<int>> buckets(bucketSize);
	for(int n : nums){
		int i = (n - minNum) / len;
		if(buckets[i].empty()){
			buckets[i].push_back(n);
			buckets[i].push_back(n);
		}
		else{
			buckets[i][0] = min(buckets[i][0], n);
			buckets[i][1] = max(buckets[i][1], n);
		}
	}

	int prev = 0;
	int res = 0;
	for(int i = 1; i < bucketSize; ++i){
		if(buckets[i].empty()) continue;
		res = max(res, buckets[i][0] - buckets[prev][1]);
		prev = i;
	}

	return res;
}

