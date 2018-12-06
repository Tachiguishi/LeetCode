#include <solution.h>

int Solution::titleToNumber(string s){
	int res(0);
	for(char c : s){
		int cur = c - 'A' + 1;
		res = res * 26 + cur;
	}
	return res;
}
