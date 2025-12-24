class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin() , capacity.end());
int a=0;
        int ans=0;
        for(int i=0 ;i<apple.size() ; i++){
            a+=apple[i];
        }
        int cap=0;
        for(int i= capacity.size()-1 ; i>=0 ; i--){
            if(cap>=a)return ans;
            ans++;
            cap+=capacity[i];
        }
       return ans; 
    }
};