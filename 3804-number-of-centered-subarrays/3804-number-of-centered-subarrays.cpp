class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
int a=0;
        for(int i=0 ;i<nums.size() ;i++){
            unordered_set<int>u;
            int sum=0;
            for(int j=i ; j<nums.size() ; j++){
                u.insert(nums[j]);
               sum+=nums[j];
               if(u.find(sum)!=u.end()){
                a++;
               
               }
            }

        }
return a;

        
    }
};