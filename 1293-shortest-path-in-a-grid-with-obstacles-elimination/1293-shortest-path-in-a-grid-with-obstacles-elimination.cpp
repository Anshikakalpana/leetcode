class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m,n;
    const int MAX=INT_MAX-2;
    vector<vector<int> > dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size(), n=grid[0].size();
        if((m+n-2)<=k)
            return m+n-2;
        dp.resize(m,vector<vector<int>>(n,vector<int>(m+n,0)));
        return solve(grid, m - 1, n - 1, k, k);
    }
    
    int solve(vector<vector<int>>& grid, int x, int y, int z, int &k){
        
        //Reached destination
        if(x == 0 && y  == 0) return 0;
        
        if(dp[x][y][z]) return dp[x][y][z];

        // can't go further
        if(z==0 && grid[x][y]==1)
            return dp[x][y][0]=MAX;

        // optimisation
        if(z>=(x+y))
            return dp[x][y][z]=(x+y);

        dp[x][y][z]=MAX;
        int nx, ny;
        for(vector<int> &dir: dirs){
            nx=x+dir[0], ny=y+dir[1];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                dp[x][y][z]=min(dp[x][y][z], solve(grid,nx,ny,z-grid[x][y],k) + 1);
            }
        }

        if(z==k && x==(m-1) && y==(n-1) && dp[x][y][z]==MAX)    return dp[x][y][z]= -1;
        return dp[x][y][z];

    }
};