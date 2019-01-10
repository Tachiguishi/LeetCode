#include <solution.h>

void Solution::reverseWords(vector<char>& str){
	int start = 0;
	int end = str.size() - 1;
	int wordLen(0);
	int count(0);
	while(start < end && count++ <= end){
		char c = str[end];
		if(c == ' '){
			start += wordLen;
			wordLen = 0;
		}
		else{
			wordLen++;
		}

		for(int i = end; i > start; --i){
			str[i] = str[i - 1];
		}
		str[start] = c;
		if(c == ' ') ++start;
	}
}
