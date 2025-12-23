class Solution {
public:
    vector<int> sumZero(int n) {
vector<int>v;
        if(n%2){
            v.push_back(0);
           
        }
       for(int i=0 ;i<n/2 ; i++){
                int x=i+1;
                v.push_back(x);
                 v.push_back(-x);
            }
            return v;
    }
};