#include <solution.h>

void Solution::rotate(vector<int>& nums, int k){
	size_t n = nums.size();
	if(n <= 1) return;

	k = k % n;
	for(int i = 1; i <= k; ++i){
		int end = nums[n - 1];
		for(size_t j = n - 1; j > 0; --j){
			nums[j] = nums[j - 1];
		}
		nums[0] = end;
	}
}
