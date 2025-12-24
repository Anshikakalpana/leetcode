class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);
        int l = s.length() - 1;
        int index = -1;

        for (int i = l; i > 0; i--) {
            if (s[i] > s[i - 1]) {

                int j = l;
                while (s[j] <= s[i - 1]) {  
                    j--;
                }

                swap(s[j], s[i - 1]);
                index = i;
                break;
            }
        }

        if (index == -1) return -1;

        string temp = "";
        for (int i = index; i <= l; i++) {
            temp += s[i];
        }

        sort(temp.begin(), temp.end());

        string str = s.substr(0, index);
        str += temp;

        long long x = stoll(str);
        if (x > INT_MAX) return -1;

        return (int)x;
    }
};