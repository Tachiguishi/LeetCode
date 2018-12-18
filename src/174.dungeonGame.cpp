#include <solution.h>
#include <iostream>

inline int calculateHP(int leftHP, int damage){
	int res(1);
	if(damage < leftHP){
		res = leftHP - damage;
	}

	return res;
}

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon){
	if(dungeon.empty() || dungeon[0].empty()) return 0;

	int down = dungeon.size();
	int right = dungeon[0].size();
	int hp[down][right];

	hp[down - 1][right - 1] = calculateHP(1, dungeon[down - 1][right - 1]);

	for(int i = down - 2; i >= 0; --i){
		hp[i][right - 1] = calculateHP(hp[i+1][right-1], dungeon[i][right-1]);
	}

	for(int i = right - 2; i >= 0; --i){
		hp[down - 1][i] = calculateHP(hp[down - 1][i+1], dungeon[down - 1][i]);
	}

	for(int i = down - 2; i >= 0; --i){
		for(int j = right - 2; j >= 0; --j){
			int t1 = calculateHP(hp[i+1][j], dungeon[i][j]);
			int t2 = calculateHP(hp[i][j+1], dungeon[i][j]);
				hp[i][j] = min(t1, t2);
		}
	}

	for(int i = 0; i < down; ++i){
		for(int j = 0; j < right; ++j){
			cout << hp[i][j] << " ";
		}
		cout << endl;
	}

	return hp[0][0];
}
