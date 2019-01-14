#include <solution.h>

vector<string> Solution::findRepeatedDnaSequences(string s){
	vector<string> res;
	size_t sLen = s.size();
	if(sLen <= 10) return res;

	int seqLen(10);
	map<string, int> dnaseq;
	for(size_t i = 0; i < sLen - 9; ++i){
		if(++dnaseq[s.substr(i, seqLen)] == 2){
			res.push_back(s.substr(i, seqLen));
		}
	}

	return res;
}
