class Solution {
public:
    int dp[500][500];
    int m;
    int n;

    int check(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i >= m || j >= n) return INT_MIN;

        if (dp[i][j] != INT_MIN) return dp[i][j];

        int take = nums1[i] * nums2[j];
        int next = check(nums1, nums2, i + 1, j + 1);
        if (next > 0) take += next;

        int nottake = max(
            check(nums1, nums2, i + 1, j),
            check(nums1, nums2, i, j + 1)
        );

        return dp[i][j] = max(take, nottake);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MIN;
            }
        }

        return check(nums1, nums2, 0, 0);
    }
};
