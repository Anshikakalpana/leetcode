class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); //meetings according to start tike

        vector<long long> count(n, 0);// how many times room was used

        priority_queue<int, vector<int>, greater<int>> available; 
        for (int i = 0; i < n; i++) available.push(i);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

           
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [t, room] = busy.top();
                busy.pop();
                busy.push({t + (end - start), room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
            if (count[i] > count[ans]) ans = i;

        return ans;
    }
};
