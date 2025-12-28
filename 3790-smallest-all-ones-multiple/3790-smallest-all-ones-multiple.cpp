class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1; // must add

        long long x = 0;
        int a = 0;

        while (x < (long long)k) {
            x = x * 10 + 1;
            a++;
        }

        while ((x % (long long)k) != 0) {
            x = (x % k) * 10 + 1;
            a++;
        }

        return a;
    }
};
