class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs[0].length();
        unordered_set<int> s;

        vector<bool> ok(strs.size() - 1, false);

        for (int i = 0; i < n; i++) {
            if (s.count(i)) continue;

            bool bad = false;
            for (int j = 0; j < strs.size() - 1; j++) {
                if (!ok[j] && strs[j][i] > strs[j + 1][i]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++;
                s.insert(i);
                continue;
            }

            for (int j = 0; j < strs.size() - 1; j++) {
                if (!ok[j] && strs[j][i] < strs[j + 1][i]) {
                    ok[j] = true;
                }
            }
        }
        return ans;
    }
};
