#include <solution.h>

const string splitChar = ".";
int popSubVersion(string& version, int start, string::size_type& end){
	int res(0);
	if(version.size() <= (size_t)start){
		end = version.size();
		return res;
	}
	end = version.find(splitChar, start);
	if(string::npos == end){
		end = version.size();
		return res;
	}
	for(int i = start; i < (int)end; ++i){
		res = 10*res + version[i] - '0';
	}
	++end;
	return res;
}

int compareVersion(string& version1, string& version2, int start1, int start2){
	string::size_type end1;
	string::size_type end2;
	int v1 = popSubVersion(version1, start1, end1);
	int v2 = popSubVersion(version2, start2, end2);
	if(v1 > v2) return 1;
	if(v1 < v2) return -1;
	if(version1.size() == end1 && version2.size() == end2) return 0;
	return compareVersion(version1, version2, (int)end1, (int)end2);
}

int Solution::compareVersion(string version1, string version2){
	version1.append(".");
	version2.append(".");
	return ::compareVersion(version1, version2, 0, 0);
}
