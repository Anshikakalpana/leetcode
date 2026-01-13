class Solution {
public:
    pair<double,double> checkArea(double mid ,vector<vector<int>>& squares){
        double a = 0;
        double b = 0;

        for(int i = 0; i < squares.size(); i++){
            if((double)squares[i][1] <= mid){
                double x = min(mid - (double)squares[i][1],
                               (double)squares[i][2]) 
                           * (double)squares[i][2];

                if(squares[i][1] + squares[i][2] <= mid){
                    a += (double)squares[i][2] * (double)squares[i][2];
                } else {
                    a += x;
                    b += ((double)squares[i][2] * (double)squares[i][2]) - x;
                }
            }
            else{
                b += (double)squares[i][2] * (double)squares[i][2];
            }
        }
        return {a, b};
    }

    double separateSquares(vector<vector<int>>& squares) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < squares.size(); i++){
            mini = min(mini, squares[i][1]);
            maxi = max(maxi, squares[i][1] + squares[i][2]);
        }

        double s = mini;
        double e = maxi;

        while(e - s > 1e-6){
            double mid = (s + e) / 2.0;

            pair<double,double> x = checkArea(mid, squares);

            if(x.first < x.second) s = mid;
          
            else e = mid;
        }
        return s;
    }
};
