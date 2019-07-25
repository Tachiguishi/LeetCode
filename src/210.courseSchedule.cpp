#include <solution.h>

bool isCycle(int n, vector<bool>& visitFlag, vector<bool>& pollFlag, vector<vector<int>>& courses, vector<int>& orderRes){
	if(pollFlag[n]){
		return true;
	}
	if(visitFlag[n]){
		return false;
	}
	pollFlag[n] = true;
	visitFlag[n] = true;
	for(auto i : courses[n]){
		if(isCycle(i, visitFlag, pollFlag, courses, orderRes)){
			return true;
		}
	}
	orderRes.push_back(n);
	pollFlag[n] = false;
	return false;
}

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites){
	vector<int> res;

	vector<vector<int>> courses(numCourses);
	for(auto& prerequire : prerequisites){
		courses[prerequire[0]].push_back(prerequire[1]);
	}

	vector<bool> visitFlag(numCourses, false);
	for(int i = 0; i < numCourses; ++i){
		if(visitFlag[i]){
			continue; 
		}

		vector<bool> pollFlag(numCourses, false);
		if(isCycle(i, visitFlag, pollFlag, courses, res)){
			res.clear();
			return res;
		}
	}

	return res;
}
