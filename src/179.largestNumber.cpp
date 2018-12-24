#include <solution.h>
#include <algorithm>

bool numCompl(const string& lhs, const string& rhs){
	size_t l = 0;
	size_t r = 0;
	while(l < lhs.size() && r < rhs.size()){
		if(lhs[l] > rhs[r]) return true;
		if(lhs[l] < rhs[r]) return false;
		++l, ++r;
		if(l >= lhs.size() && r >= rhs.size()) return true;
		if(l >= lhs.size()) l = lhs.size() - 1;
		if(r >= rhs.size()) r = rhs.size() - 1; 
	}
	return false;
}

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
	sort(numstr.begin(), numstr.end(), numCompl);
	if(numstr[0][0] == '0') return "0";
	string res;
	res.clear();
	for(size_t i = 0; i < numstr.size(); ++i){
		res.append(numstr[i]);
	}
	return res;
}
