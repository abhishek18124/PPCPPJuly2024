class Solution {
public:

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	int dfs(int i, int j, const vector<vector<int>>& grid,
	        vector<vector<bool>>& vis, int m, int n) {

		// find out the size of the component in which (i, j)th cell is present

		vis[i][j] = true;
		int cnt = 1; // cnt is init with 1 to take into acc. (i, j)th cell

		// int nx = i;
		// int ny = j + 1;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		//                 grid[nx][ny] == 1 and
		//                 !vis[nx][ny]) {

		// 	cnt += dfs(nx, ny, grid, vis, m, n);

		// }

		// nx = i;
		// ny = j - 1;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		//                 grid[nx][ny] == 1 and
		//                 !vis[nx][ny]) {

		// 	cnt += dfs(nx, ny, grid, vis, m, n);

		// }

		// nx = i - 1;
		// ny = j;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		//                 grid[nx][ny] == 1 and
		//                 !vis[nx][ny]) {

		// 	cnt += dfs(nx, ny, grid, vis, m, n);

		// }

		// nx = i + 1;
		// ny = j;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and
		//                 grid[nx][ny] == 1 and
		//                 !vis[nx][ny]) {

		// 	cnt += dfs(nx, ny, grid, vis, m, n);

		// }

		for (int k = 0; k < 4; k++) {

			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and
			                grid[nx][ny] == 1 and
			                !vis[nx][ny]) {

				cnt += dfs(nx, ny, grid, vis, m, n);

			}


		}



		return cnt;

	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<bool>> vis(m, vector<bool>(n, false));
		int maxSofar = 0; // to track the area of the largest island

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 and !vis[i][j]) {
					// (i,j)th cell corresponds to a node that is not yet visited
					maxSofar = max(maxSofar, dfs(i, j, grid, vis, m, n));
				}
			}
		}

		return maxSofar;

	}
};