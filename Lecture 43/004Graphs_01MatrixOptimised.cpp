class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    // (i, j)th cell is src node
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = { -1, 1, 0, 0};

        while (!q.empty()) {

            pair<int, int> p = q.front(); q.pop();
            int i = p.first;
            int j = p.second;

            // auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 and nx < m and ny >= 0 and ny < n and d[nx][ny] == INT_MAX) {
                    // (nx, ny) is not yet visited / (nx, ny) distance is not yet computed
                    d[nx][ny] = d[i][j] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return d;
    }
};