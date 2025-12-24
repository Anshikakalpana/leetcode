class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (visited[i][j] || grid[i][j] == '0') return;

        visited[i][j] = true;

        vector<pair<int,int>> v = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for (auto id : v) {
            int x = i + id.first;
            int y = j + id.second;
            dfs(x, y, grid, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return ans;
    }
};
