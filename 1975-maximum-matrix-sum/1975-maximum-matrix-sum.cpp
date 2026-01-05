class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
int n=0;
long long ans=0;
int mini= INT_MAX;
        for(int i=0 ;i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[i].size() ; j++){
                mini= min(mini , abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0)n++;
            }
        }
          if(n&1)return ans-2*mini;
          return ans;
       
        
    }
};