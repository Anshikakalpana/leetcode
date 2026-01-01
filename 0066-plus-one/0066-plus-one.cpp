class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool big = false;
        vector<int> ans(digits.size() + 1, 0);

        for (int i = digits.size() - 1; i >= 0; i--) {
            int x = 0;
            if(i==digits.size() - 1){
             x=   digits[i]+1;
            }
            else{
                x=digits[i];
            }
            digits[i] = x % 10;

            if (x > 9) {
                if (i == 0) {
                    big = true;   // carry goes beyond most significant digit
                } else {
                    digits[i - 1] += 1;
                }
            } else {
                break;
            }
        }

        if (big) {
            ans[0] = 1;
            for (int i = 0; i < digits.size(); i++) {
                ans[i + 1] = digits[i];
            }
            return ans;
        } else {
            for (int i = 0; i < digits.size(); i++) {
                ans[i] = digits[i];
            }
            ans.pop_back(); 
            return ans;
        }
    }
};
