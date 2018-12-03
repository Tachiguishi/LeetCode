#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace leetcode{

struct TwoStringOneInt{
	string str1;
	string str2;
	int int1;
	TwoStringOneInt(const char* s1, const char* s2, int i):
	str1(s1), str2(s2), int1(i){}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for(int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ",";
	}
	return "[" + result.substr(0, result.length() - 1) + "]";
}

} // end of namespace leetcode