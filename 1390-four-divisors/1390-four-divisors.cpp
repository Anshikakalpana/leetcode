class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        vector<int>a(1e5+1 ,1);
vector<int>sum(1e5+1 ,1);


        for(int i=2 ; i<=1e5 ; i++){
            for(int j=i ; j<=1e5 ; j+=i){
               a[j]++;
               sum[j]+=i;
            }
        }
        int ans=0;
        for(int i=0 ;i<nums.size() ; i++){
            if(a[nums[i]]==4){
                ans+=sum[nums[i]];
            }
        }
        return ans;
    }
};