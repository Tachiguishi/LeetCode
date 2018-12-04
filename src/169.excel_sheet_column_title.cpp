#include <solution.h>


string Solution::convertToTitle(int n){
	const int ary = 26;
	string res;
	while(n > 0){
		int remanider = (n - 1) % ary;
		n = n / ary;
		res.push_back('A' + remanider);
		if(remanider == (ary -1)) --n;
	}
	for(size_t i = 0; i < res.size() / 2; ++i){
		swap(res[i], res[res.size() - 1 - i]);
	}
	return res;
}
