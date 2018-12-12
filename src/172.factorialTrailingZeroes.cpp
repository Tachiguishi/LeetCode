#include <solution.h>

int Solution::trailingZeroes(int n){
	int count(0);
	int i(5);
	while(n > 0){
		count += n / i;
		n = n / 5;
	}
	return count;
}
