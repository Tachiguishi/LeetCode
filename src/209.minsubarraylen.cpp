#include <solution.h>

int Solution::minSubArrayLen(int s, vector<int>& nums){
	int sum = 0;
	int resLen = (int)nums.size() + 1;
	for(size_t i = 0, j = 0; j < nums.size(); ++j){
		if(nums[j] >= s) return 1;

		sum += nums[j];
		if(sum < s){
			continue;
		}
		resLen = min(resLen, int(j - i + 1));
		while(i < j){
			sum -= nums[i];
			if(sum < s){
				i++;
				break;
			}
			i++;
			resLen = min(resLen, int(j - i + 1));
		}
	}

	return (resLen > (int)nums.size()) ? 0 : resLen;
}
