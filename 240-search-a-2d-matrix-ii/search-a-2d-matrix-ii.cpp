class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0 ;i<matrix.size() ; i++){
            if(matrix[i][0]>target)return false;
            int s=0;
            int e=matrix[i].size()-1;
            while(s<=e){
               int mid = s + (e - s) / 2;

                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]<target)s= mid+1 ;
                else{
                    e= mid-1;
                }

            }
        }
        return false;
    }
};