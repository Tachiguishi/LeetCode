#include <solution.h>
#include <climits>
#include <cmath>
#include <map>

string Solution::fractionToDecimal(int numerator, int denominator){
	if(0 == denominator) return "NaN";
	if(0 == numerator) return "0";
	string res;
	int quotient(0);
	int remainder(0);
	if(INT_MIN == numerator && (denominator == -1 || denominator == 1)){
		quotient = numerator;
	}
	else{
		quotient = numerator / denominator;
		remainder = std::abs(numerator % denominator);
	}

	if(0 == quotient){
		if((numerator > 0 && denominator < 0)
			|| (numerator < 0 && denominator > 0)){
				res.push_back('-');
			}
		res.push_back('0');
	}
	else{
		bool negative(false);
		if(quotient < 0 && -1 != denominator){
			negative = true;
		}
		while(quotient){
			int f = quotient % 10;
			res.push_back(std::abs(f) + '0');
			quotient = quotient / 10;
		}
		if(negative) res.push_back('-');
		for(int i = 0; i < (int)res.size()/2; ++i){
			std::swap(res[i], res[res.size()-1-i]);
		}
	}
	if(0 != remainder){
		res.push_back('.');
	}
	else{
		return res;
	}

	bool irrational(false);
	int tailSize(0);
	long long lnumerator;
	std::map<int,int> remainders;
	string resTail;
	while(remainder){
		if(remainders.count(remainder)){
			tailSize = remainders[remainder];
			irrational = true;
			break;
		}

		remainders[remainder] = tailSize++;

		lnumerator = (long long)remainder * 10;
		quotient = lnumerator / denominator;
		remainder = std::abs(lnumerator % denominator);

		resTail.push_back(std::abs(quotient) + '0');
	}

	res.append(resTail.substr(0, tailSize));
	if(irrational){
		res.push_back('(');
		res.append(resTail.substr(tailSize));
		res.push_back(')');
	}

	return res;
}
