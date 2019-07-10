#include <solution.h>

bool isCycle(int n, vector<bool>& visitFlag, vector<bool>& pollFlag, vector<vector<int>> courses){
	if(pollFlag[n]){
		return true;
	}
	pollFlag[n] = true;
	visitFlag[n] = true;
	for(auto i : courses[n]){
		if(isCycle(i, visitFlag, pollFlag, courses)){
			return true;
		}
	}
	pollFlag[n] = false;
	return false;
}

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites){
	if(numCourses <= 0){
		return true;
	}

	vector<vector<int>> courses(numCourses);
	for(auto& prerequire : prerequisites){
		courses[prerequire[0]].push_back(prerequire[1]);
	}

	vector<bool> visitFlag(numCourses, false);
	for(size_t i = 0; i < courses.size(); ++i){
		if(courses[i].empty() || visitFlag[i]){
			continue; 
		}

		vector<bool> pollFlag(numCourses, false);
		if(isCycle(i, visitFlag, pollFlag, courses)){
			return false;
		}
	}
	return true;
}
