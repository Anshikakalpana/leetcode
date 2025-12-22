class Solution {
public:
    int arraySign(vector<int>& nums) {
int ans=0;
        for(int i=0 ;i<nums.size() ; i++){
            if(nums[i]==0)return 0;
            else if(nums[i]<0) ans++;
        }
        if(ans%2)return -1;
        return 1;
        
    }
};