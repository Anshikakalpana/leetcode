class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
sort(happiness.begin() , happiness.end());
long long sum=0;
                int l = happiness.size()-1;
                 int r=0;
                 for(int i=l ; i>=0 ; i--){
                    if(r==k)break;
                    happiness[i]=happiness[i]-r;

                      if(happiness[i]<=0 )break;


                    sum= sum+ (happiness[i]);
                    r++;

                 }

           return      sum;
                     

        
    }
};