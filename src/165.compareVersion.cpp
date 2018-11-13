#include <solution.h>

const string splitChar = ".";
int compareVersion(string& version1, string& version2, int startIndex){
	string::size_type left = version1.find(splitChar, startIndex);
	string::size_type right = version2.find(splitChar, startIndex);
	if(string::npos == left && string::npos == right) return 0;
	if(string::npos == left && string::npos != right) return -1;
	if(string::npos != left && string::npos == right) return 1;
	int v1 = stoi(version1.substr(startIndex, left - startIndex));
	int v2 = stoi(version2.substr(startIndex, right - startIndex));
	if(v1 > v2) return 1;
	if(v1 < v2) return -1;
	return compareVersion(version1, version2, left+1);
}

int Solution::compareVersion(string version1, string version2){
	return ::compareVersion(version1, version2, 0);
}
