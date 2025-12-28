// class Solution {
// public:
// int dp[]
//     bool check(string &s, string &t, int i, int j) {
//         if (j == t.size()) return true;
//         if (i == s.size()) return false;

//         if (s[i] == t[j]) {
//             if (check(s, t, i + 1, j + 1)) return true;
//         }
//         return check(s, t, i + 1, j);
//     }

//     int numMatchingSubseq(string s, vector<string>& words) {
//         int ans = 0;
//         for (int i = 0; i < words.size(); i++) {
//             if (check(s, words[i], 0, 0)) ans++;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
	
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
		
		
        map<string, bool> mp;
        for(auto x: words){
		
            if(mp.find(x) != mp.end()) {
                if(mp[x] == true) {
                    count++;
                }
				
                continue;
            }
			
		
            mp[x] = isSubsequence(s, x, s.size(), x.size());
            count += (mp[x] == true);
        }
		
        return count;
    }
};