#include <solution.h>

int Solution::rob(vector<int>& nums){
	int res(0);
	int prev(0);

	for(int n : nums){
		int tmp = res;
		res = std::max(prev + n, res);
		prev = tmp;
	}

	return res;
}

