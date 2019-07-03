#include <solution.h>

int ROW(0);
int COL(0);

void dfs(vector<vector<char>>& grid, int row, int col){
	if(row < 0 || row >= ROW || col < 0 || col >= COL){
		return;
	}

	if(grid[row][col] == '0'){
		return;
	}

	grid[row][col] = '0';
	dfs(grid, row, col - 1);
	dfs(grid, row, col + 1);
	dfs(grid, row - 1, col);
	dfs(grid, row + 1, col);
}

int Solution::numIslands(vector<vector<char>>& grid){
	int res(0);
	if(grid.empty()){
		return res;
	}

	ROW = grid.size();
	COL = grid[0].size();

	for(int row = 0; row < ROW; row++){
		for(int col = 0; col < COL; col++){
			if(grid[row][col] == '1'){
				res++;
				dfs(grid, row, col);
			}
		}
	}
	return res;
}
