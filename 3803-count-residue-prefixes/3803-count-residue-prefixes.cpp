class Solution {
public:
    int residuePrefixes(string s) {
int a=0;
        unordered_map<char , int>u;
        for(int i=0 ;i<s.length() ; i++){
            u[s[i]]++;
            if(u.size()==((i+1)%3))a++;
        }

return a;
        
    }
};