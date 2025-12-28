class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<long long> mins(n);
        vector<long long> pre(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        mins[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mins[i] = min((long long)nums[i], mins[i + 1]);
        }

        long long maxi = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            long long x = pre[i] - mins[i + 1];
            maxi = max(maxi, x);
        }

        return maxi;
    }
};
