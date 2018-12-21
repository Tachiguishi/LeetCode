#include <solution.h>
#include <algorithm>

string Solution::largestNumber(vector<int>& nums){
	vector<string> numstr;
	for(auto i : nums){
		int n = 10;
		string s;
		while(i){
			int tmp = i % n;
			s.push_back(tmp + '0');
			i = i / n;
		}
		for(size_t i = 0; i < s.size() / 2; ++i){
			swap(s[i], s[s.size() - 1 - i]);
		}
		numstr.push_back(s);
	}
	sort(numstr.begin(), numstr.end());
	string res;
	res.clear();
	for(size_t i = numstr.size() - 1; i >= 0; --i){
		res.append(numstr[i]);
	}
	return res;
}
