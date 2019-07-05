#include <solution.h>

int calcHappy(int n){
	int res{0};
	while(n != 0){
		int tmp = n % 10;
		res += tmp * tmp;
		n = n / 10;
	}
	return res;
}

bool Solution::isHappy(int n){
	set<int> res;
	while(n != 1){
		n = calcHappy(n);
		if(res.find(n) != res.end()){
			return false;
		}
		else{
			res.insert(n);
		}
	}
	return true;
}
