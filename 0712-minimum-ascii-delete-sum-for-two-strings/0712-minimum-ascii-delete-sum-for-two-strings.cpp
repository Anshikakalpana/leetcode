class Solution {
public:
    int dp[1001][1001];

    int solve(string& s1, string& s2, int i, int j,vector<int>& p1 , vector<int>&p2) {
        if (i >= s1.size() && j >= s2.size()) {
            return 0;
        }

        if (i >= s1.size()) {
           int sum=0;
            sum+=p2[j];
            return sum;
        }

        if (j >= s2.size()) {
            int sum=0;
            sum+=p1[i];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans;
        if (s1[i] == s2[j]) {
            ans = solve(s1, s2, i + 1, j + 1 ,p1,p2);
        } else {
            int delete1 = (int)s1[i] + solve(s1, s2, i + 1, j ,p1,p2);
            int delete2 = (int)s2[j] + solve(s1, s2, i, j + 1,p1,p2);
            ans = min(delete1, delete2);
        }

        return dp[i][j] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
     int m = s1.length();
     int n= s2.length();
        vector<int>prefix1(m,0);
        vector<int>prefix2(n,0);
         prefix1[m-1]= int(s1[m-1]);
          prefix2[n-1]= int(s2[n-1]);

        for(int i= m-2 ; i>=0 ; i--){
            prefix1[i]= prefix1[i+1]+int(s1[i]) ;
        }

           for(int i= n-2 ; i>=0 ; i--){
            prefix2[i]= prefix2[i+1]+int(s2[i]) ;
        }

        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0 , prefix1 ,prefix2);
    }
};