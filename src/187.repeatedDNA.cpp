#include <solution.h>

vector<string> Solution::findRepeatedDnaSequences(string s){
	vector<string> res;
	size_t sLen = s.size();
	if(sLen <= 19) return res;

	int seqLen(10);
	map<string, int> dnaseq;
	for(size_t i = 0; i < sLen - 19; ++i){
		if(dnaseq[s.substr(i, seqLen)] > 1){
			continue;
		}
		dnaseq[s.substr(i, seqLen)] = 1;

		for(size_t j = i + 10; j < sLen - 9; ++j){
			if(dnaseq[s.substr(j, seqLen)] > 0){
				++dnaseq[s.substr(j, seqLen)];
				break;
			}
		}
	}

	for(auto dna : dnaseq){
		if(dna.second > 1){
			res.push_back(dna.first);
		}
	}

	return res;
}
