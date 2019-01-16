#include <solution.h>

int anytimesMaxProfix(vector<int>& prices){
	int res(0);
	for(size_t i = 1; i < prices.size(); ++i){
		int diff = prices[i] - prices[i - 1];
		if(diff > 0){
			res += diff;
		}
	}
	return res;
}

int Solution::maxProfit(int k, vector<int>& prices){
	if(k <= 0) return 0;
	size_t n = prices.size();
	if(n <= 1) return 0;

	if((size_t)k >= n) return anytimesMaxProfix(prices);

	int g[k+1] = {0}, l[k+1] = {0};
	for(size_t i = 1; i < n; ++i){
		int diff = prices[i] - prices[i-1];
		for(int j = k; j > 0; --j){
			l[j] = max((g[j-1] + max(diff, 0)), l[j] + diff);
			g[j] = max(g[j], l[j]);
		}
	}

	return g[k];
}
