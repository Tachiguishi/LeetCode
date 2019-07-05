#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <struct_define.h>

using namespace std;

namespace leetcode{

struct TwoStringOneInt{
	string str1;
	string str2;
	int int1;
	TwoStringOneInt(const char* s1, const char* s2, int i):
	str1(s1), str2(s2), int1(i){}
};

struct OneStringTwoInt{
	string str1;
	int int1;
	int int2;
	OneStringTwoInt(const char* s1, int i, int j):
	str1(s1), int1(i), int2(j){}
};

struct IntToggleString{
	string str1;
	int int1;
	IntToggleString(int i, const char* str):
	str1(str), int1(i){}
};

struct TwoString{
	string str1;
	string str2;
	TwoString(const char* s1, const char* s2):
	str1(s1), str2(s2){}
};

struct BoolToggleInt{
	bool vaild;
	int int1;
	BoolToggleInt(bool val, int i):
	vaild(val), int1(i){}
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

vector<char> stringToCharVector(string input){
	vector<char> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while(getline(ss, item, delim)){
		output.push_back(item[0]);
	}
	return output;
}

vector<vector<int>> stringTo2DIntegerVector(string input){
	vector<vector<int>> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = '.';
	while(getline(ss, item, delim)){
		output.push_back(stringToIntegerVector(item));
	}
	return output;
}

vector<vector<char>> stringTo2DCharVector(string input){
	vector<vector<char>> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = '.';
	while(getline(ss, item, delim)){
		output.push_back(stringToCharVector(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
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

string charVectorToString(vector<char> list, int length = -1){
	if(length == -1){
		length = list.size();
	}

	if(length == 0){
		return "[]";
	}

	string result;
	for(int index = 0; index < length; ++index){
		result.push_back(list[index]);
		result += ",";
	}
	return "[" + result.substr(0, result.length() - 1) + "]";
}

string stringVectorToString(vector<string> list, int length = -1){
	if(length == -1){
		length = list.size();
	}

	if(length == 0){
		return "[]";
	}

	string result;
	for(int index = 0; index < length; ++index){
		result += list[index] + ",";
	}
	return "[" + result.substr(0, result.length() - 1) + "]";
}

uint32_t stringBitsToInteger(string input){
	uint32_t res;
	for(int i = input.size() - 1; i >= 0; --i){
		if(input[i] == '1'){
			res += (1 << (input.size() - 1 - i));
		}
	}
	return res;
}

string IntegerToStringBits(uint32_t input){
	string res;
	for(int i = 31; i >= 0; --i){
		if(input & (1 << i)){
			res.push_back('1');
		}
		else{
			res.push_back('0');
		}
	}
	return res;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for(int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ",";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

} // end of namespace leetcode
