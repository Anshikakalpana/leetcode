class Solution {
public:
unordered_set<int>s;

    int repeatedNTimes(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            if(s.find(nums[i])!=s.end())return nums[i];
            s.insert(nums[i]);
        }
        return 0;
    }
};