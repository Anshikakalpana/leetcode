// class Solution {
// public:
// int dp[m][n];

// int check(int row, int col, vector<vector<int>>& cells , int i , int j , vector<vector<bool>>&vis){
//     if(i==row-1)return true;
//     if(i>=row || j>=col || i<0 || j<0 || grid[i][j]) return false;

//     if(dp[i][j]!=-1)return dp[i][j];

//     vector<pair<int , int>v={{-1,0} ,{1,0} ,{0,1} ,{0,-1}};
//               for(auto ind:v){
//                 int x= ind.first+i;
//                 int y= ind.second + j;
//                 vis[x][y]=true;
//                 if(!vis[x][y])check(row, col , cells , x,y , vis );

                
//               }
//               return false;

// }
//     int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

//         vector<vector<int>grid(row , vector<int>(col ,0));
//         for(int i=0 ; i<cells.size() ; i++){
//             grid[cells[i][0]][cells[i][1]]=1;
//             if(int j=0 ;j<col ; j++){
//                 if(check(row , col , cells , 0 , j ,vis)){
//                     ans++;
//                     break;
//                 }
//             }
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    int row, col;
    vector<vector<int>> grid;
    vector<vector<bool>> vis;

    bool check(int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col) return false;
        if (grid[i][j] == 1 || vis[i][j]) return false;

        if (i == row - 1) return true;   // ✅ moved AFTER checks

        vis[i][j] = true;

        if (check(i + 1, j)) return true;
        if (check(i - 1, j)) return true;
        if (check(i, j + 1)) return true;
        if (check(i, j - 1)) return true;

        return false;
    }

    bool possible(int day, vector<vector<int>>& cells) {
        grid.assign(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                vis.assign(row, vector<bool>(col, false));
                if (check(0, j)) return true;
            }
        }
        return false;
    }

    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r;
        col = c;

        int low = 1, high = cells.size(), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(mid, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
