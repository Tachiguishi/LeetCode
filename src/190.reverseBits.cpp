#include <solution.h>

uint32_t Solution::reverseBits(uint32_t n){
	uint32_t res(0);
	for(int i = 0; i < 32; ++i){
		if(n & (1 << i)){
			res ^= 1 << (31 - i);
		}
	}
	return res;
}
