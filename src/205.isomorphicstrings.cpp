#include <solution.h>

bool Solution::isIsomorphic(string s, string t){
	map<char, char> dictA;
	map<char, char> dictB;
	for(size_t i = 0; i < s.size(); i++){
		if(dictA.find(s[i]) == dictA.end()){
			// not find s[i]
			dictA[s[i]] = t[i];
		}
		else{
			if(dictA[s[i]] != t[i]) return false;
		}

		if(dictB.find(t[i]) == dictB.end()){
			dictB[t[i]] = s[i];
		}
		else{
			if(dictB[t[i]] != s[i]) return false;
		}
	}

	return true;
}
