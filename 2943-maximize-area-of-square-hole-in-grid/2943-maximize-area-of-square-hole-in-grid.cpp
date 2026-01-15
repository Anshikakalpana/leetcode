class Solution {
public:

    int maxi(vector<int>& bars) {
        int res = 1;
        int streak = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                streak++;
                continue;
            }
            res = max(res, ++streak);
            streak = 1;
        }
        return max(res, ++streak);
    }

      int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        return pow(min(maxi(hBars), maxi(vBars)), 2);
    }
};