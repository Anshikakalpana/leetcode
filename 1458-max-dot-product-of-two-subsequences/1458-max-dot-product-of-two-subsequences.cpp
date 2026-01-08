class Solution {
public:
    // dp[i][j] stores the maximum dot product we can get
    // starting from index i in nums1 and index j in nums2
    int dp[500][500];

    // sizes of the two arrays
    int m;
    int n;

    // recursive function to compute max dot product
    int check(vector<int>& nums1, vector<int>& nums2, int i, int j) {

        // if we reach the end of either array,
        // return INT_MIN to avoid choosing empty subsequence
        if (i >= m || j >= n) return INT_MIN;

        // if already computed, return stored value
        if (dp[i][j] != INT_MIN) return dp[i][j];

        // option 1: take current pair nums1[i] and nums2[j]
        int take = nums1[i] * nums2[j];

        // move both indices forward
        int next = check(nums1, nums2, i + 1, j + 1);

        // add future result only if it increases the sum
        if (next > 0) take += next;

        // option 2: skip nums1[i]
        // option 3: skip nums2[j]
        int nottake = max(
            check(nums1, nums2, i + 1, j),
            check(nums1, nums2, i, j + 1)
        );

        // store and return the best of take and nottake
        return dp[i][j] = max(take, nottake);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        // store sizes
        m = nums1.size();
        n = nums2.size();

        // initialize dp array with INT_MIN
        // INT_MIN means "not computed yet"
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MIN;
            }
        }

        // start recursion from index 0,0
        return check(nums1, nums2, 0, 0);
    }
};
