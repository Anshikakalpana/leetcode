class Solution {
public:
    int dp[100][100];
    int m, n;

    int check(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {

        int ans = 0;
        vector<pair<int, int>> v = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for (auto dir : v) {
            int x = i + dir.first;
            int y = j + dir.second;

            if (x >= 0 && x < m && y >= 0 && y < n &&
                !visited[x][y] && grid[x][y] != 0) {

                visited[x][y] = true;
                ans = max(ans, grid[x][y] + check(x, y, grid, visited));
                visited[x][y] = false; // backtrack
            }
        }
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    visited[i][j] = true;
                    res = max(res, grid[i][j] + check(i, j, grid, visited));
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }
};
