class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0];
             });

        int n = events.size();
        if (n == 1) return events[0][2];

        vector<int> greatest(n);
        greatest[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            greatest[i] = max(events[i][2], greatest[i + 1]);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            // binary search for first event with start > events[i][1]
            int lo = i + 1, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (events[mid][0] > events[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            int curr = events[i][2];
            if (lo < n) {
                curr += greatest[lo];
            }

            maxi = max(maxi, curr);
        }

        return maxi;
    }
};
