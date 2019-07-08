#include <solution.h>

bool Solution::isIsomorphic(string s, string t){
	set<char> dict;
	for(size_t i = 0; i < s.size(); i++){
		if(dict.count(s[i]) > 0) continue;

		dict.insert(s[i]);
		char c = t[i];
		for(size_t j = i; j < s.size(); j++){
			if(t[j] == c){
				t[j] = s[i];
			}
		}
	}
	return s == t;
}
