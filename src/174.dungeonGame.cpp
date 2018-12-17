#include <solution.h>
#include <iostream>

struct RoleHP{
	int initial;
	int current;
	RoleHP():initial(0), current(0){}
};

inline RoleHP calculateHP(RoleHP& status, int damage){
	RoleHP res;
	res.current = status.current + damage;
	if(res.current > 0){
		res.initial = status.initial;
	}
	else{
		res.initial = status.initial - res.current + 1;
		res.current = 1;
	}
	return res;
}

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon){
	if(dungeon.empty() || dungeon[0].empty()) return 0;

	int down = dungeon.size();
	int right = dungeon[0].size();
	RoleHP hp[down][right];

	if(dungeon[0][0] > 0){
		hp[0][0].initial = 1;
		hp[0][0].current = dungeon[0][0];
	}
	else{
		hp[0][0].initial = 1 - dungeon[0][0];
		hp[0][0].current = 1;
	}

	for(int i = 1; i < down; ++i){
		hp[i][0] = calculateHP(hp[i-1][0], dungeon[i][0]);
	}

	for(int i = 1; i < right; ++i){
		hp[0][i] = calculateHP(hp[0][i-1], dungeon[0][i]);
	}

	for(int i = 1; i < down; ++i){
		for(int j = 1; j < right; ++j){
			RoleHP t1 = calculateHP(hp[i-1][j], dungeon[i][j]);
			RoleHP t2 = calculateHP(hp[i][j-1], dungeon[i][j]);
			if(t1.initial <= t2.initial){
				hp[i][j] = t1;
			}
			else{
				hp[i][j] = t2;
			}
		}
	}

	for(int i = 0; i < down; ++i){
		for(int j = 0; j < right; ++j){
			cout << hp[i][j].initial << "(" << hp[i][j].current << ") ";
		}
		cout << endl;
	}

	return hp[down-1][right-1].initial;
}
