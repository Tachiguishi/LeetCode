#include <solution.h>

int Solution::rangeBitwiseAnd(int m, int n){
	int firstM = -1;
	for(int i = 31; i >= 0; i--){
		int tmp = 1 << i;
		if((m & tmp) == (n & tmp)){
			continue;
		}
		firstM = i;
		break;
	}

	int res{m};
	for(int i = 0; i <= firstM; i++){
		res &= ~(1 << i);
		if(res == 0){
			break;
		}
	}
	return res;
}
