class Solution {
public:
    bool no(char h) {
        return (h >= '0' && h <= '9');
    }

    string decodeString(string s) {
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            if (no(s[i])) {
                int j = i;
                int num = 0;

               
                while (j < s.length() && no(s[j])) {
                    num = num * 10 + (s[j] - '0');
                    j++;
                }

                
                j++; 

                //  substring inside brackets
                string st = "";
                int open = 1;
                while (j < s.length() && open > 0) {
                    if (s[j] == '[') open++;
                    else if (s[j] == ']') open--;

                    if (open > 0)
                        st += s[j];
                    j++;
                }

          
                string decoded = decodeString(st);

                while (num--) {
                    ans += decoded;
                }

                i = j - 1; 
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};
