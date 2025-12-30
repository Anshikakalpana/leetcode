class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> u;
        for (int i = 0; i < nums.size(); i++) {
            u[nums[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int x = nums[i];
                int y = nums[j];
                int z = -(x + y);

              
                if (z < y) continue;

                if (u.find(z) == u.end()) continue;

                vector<int>& idx = u[z];
                for (int k : idx) {
                    if (k != i && k != j) {
                        ans.push_back({x, y, z});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

