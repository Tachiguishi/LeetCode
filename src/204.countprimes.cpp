#include <solution.h>

int Solution::countPrimes(int n){
	vector<bool> primes(n, true);
	for(int i = 2; i * i < n; i++){
		if(!primes[i]){
			continue;
		}

		for(int j = i * i; j < n; j += i){
			primes[j] = false;
		}
	}

	int count(0);
	for(int i = 2; i < n; i++){
		if(primes[i]) count++;
	}
	return count;
}
