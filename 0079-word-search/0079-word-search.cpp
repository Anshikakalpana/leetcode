class Solution {
public:
    int m, n;

    bool dfs(int i , int j , int k ,
             vector<vector<char>>& board,
             string word ,
             vector<vector<bool>>& visited) {

        if (k == word.size()) return true;

        vector<pair<int , int>> p = {{-1,0},{1,0},{0,-1},{0,1}};
        bool take = false;

        for (auto ps : p) {
            int x = i + ps.first;
            int y = j + ps.second;

            if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y]) {
                if (board[x][y] == word[k]) {
                    visited[x][y] = true;
                    take = dfs(x, y, k + 1, board, word, visited);
                    visited[x][y] = false;
                    if (take) return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(i, j, 1, board, word, visited))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
