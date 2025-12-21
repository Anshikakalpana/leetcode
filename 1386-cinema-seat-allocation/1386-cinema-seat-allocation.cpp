class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<bool>> u;

        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            if (!u.count(row))
                u[row] = vector<bool>(10, false);

            u[row][seat - 1] = true;
        }

        int x = u.size();
        int ans = (n - x) * 2;

        for (auto &p : u) {
            vector<bool> &v = p.second;

            bool left = true, mid = true, right = true;

            for (int i = 1; i <= 4; i++)
                if (v[i]) left = false;

            for (int i = 3; i <= 6; i++)
                if (v[i]) mid = false;

            for (int i = 5; i <= 8; i++)
                if (v[i]) right = false;

            if (left && right) ans += 2;
            else if (left || mid || right) ans += 1;
        }

        return ans;
    }
};
