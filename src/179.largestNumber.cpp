#include <solution.h>
#include <algorithm>

string Solution::largestNumber(vector<int>& nums){
	vector<string> numstr;
	for(auto i : nums){
		int n = 10;
		string s;
		do{
			int tmp = i % n;
			s.push_back(tmp + '0');
			i = i / n;
		}while(i);
		for(size_t i = 0; i < s.size() / 2; ++i){
			swap(s[i], s[s.size() - 1 - i]);
		}
		numstr.push_back(s);
	}
	sort(numstr.begin(), numstr.end(), [](string& lhs, string& rhs)->bool{
		if(lhs[0] > rhs[0]) return true;
		if(lhs[0] < rhs[0]) return false;
		return lhs + rhs > rhs + lhs;
	});
	if(numstr[0][0] == '0') return "0";
	string res;
	res.clear();
	for(size_t i = 0; i < numstr.size(); ++i){
		res.append(numstr[i]);
	}
	return res;
}
