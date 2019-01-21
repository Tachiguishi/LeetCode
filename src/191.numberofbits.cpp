#include <solution.h>

int Solution::hammingWeight(uint32_t n){
	int res(0);
	for(uint32_t i = 0; i < 32; ++i){
		if(n & (1 << i)){
			++res;
		}
	}
	return res;
}
