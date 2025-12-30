class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size(), ans = 0;
        for (int i = 0; i + 2 < r; i++)
            for (int j = 0; j + 2 < c; j++)
                ans += isMagic(g, i, j);
        return ans;
    }

    bool isMagic(vector<vector<int>>& g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        bool seen[10] = {};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int v = g[r+i][c+j];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = true;
            }

        return
            g[r][c]+g[r][c+1]+g[r][c+2]==15 &&
            g[r+1][c]+g[r+1][c+1]+g[r+1][c+2]==15 &&
            g[r+2][c]+g[r+2][c+1]+g[r+2][c+2]==15 &&
            g[r][c]+g[r+1][c]+g[r+2][c]==15 &&
            g[r][c+1]+g[r+1][c+1]+g[r+2][c+1]==15 &&
            g[r][c+2]+g[r+1][c+2]+g[r+2][c+2]==15 &&
            g[r][c]+g[r+1][c+1]+g[r+2][c+2]==15 &&
            g[r][c+2]+g[r+1][c+1]+g[r+2][c]==15;
    }
};