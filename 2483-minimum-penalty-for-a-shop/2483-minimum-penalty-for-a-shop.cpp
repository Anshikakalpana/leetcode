class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> p(n + 1, 0); // prefix Y
        vector<int> k(n + 1, 0); // prefix N

        int ans = 0, bns = 0;
        int index = 0;
        int maxi = INT_MAX;

        // build prefix arrays
        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'Y') {
                ans++;
            } else {
                bns++;
            }
            p[i] = ans;
            k[i] = bns;
        }

        // find minimum penalty
        for (int i = 0; i <= n; i++) {
            int x = p[n] - p[i]; 
            int y = k[i];       
            int t = x + y;

            if (t < maxi) {
                maxi = t;
                index = i;
            }
        }

        return index;
    }
};
