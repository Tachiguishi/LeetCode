#include <solution.h>

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites){
	if(numCourses <= 0){
		return true;
	}

	vector<int> courses(numCourses, -1);
	for(auto& prerequire : prerequisites){
		for(size_t i = 1; i < prerequire.size(); i++){
			courses[prerequire[i - 1]] = prerequire[i];
		}
	}

	vector<bool> visitFlag(numCourses, false);
	for(size_t i = 0; i < courses.size(); ++i){
		if(visitFlag[i]){
			continue;
		}
		visitFlag[i] = true;

		size_t index = i;
		vector<bool> pollFlag(numCourses, false);
		while(courses[index] != -1){
			if(pollFlag[index]){
				return false;
			}
			pollFlag[index] = true;
			index = courses[index];
			visitFlag[index] = true;
		}
	}
	return true;
}
