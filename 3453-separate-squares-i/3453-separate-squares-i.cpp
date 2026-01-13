class Solution {
public:
 
    pair<double,double> checkArea(double mid ,vector<vector<int>>& squares){
        double a = 0;   // area below mid
        double b = 0;   // area above mid

        // iterate over all squares
        for(int i = 0; i < squares.size(); i++){

            // if bottom of square is at or below mid
            if((double)squares[i][1] <= mid){

                // height of square portion lying below mid
                // min is used to avoid exceeding square height
                double x = min(mid - (double)squares[i][1],
                               (double)squares[i][2]) 
                           * (double)squares[i][2];

                // if entire square lies below mid
                if(squares[i][1] + squares[i][2] <= mid){
                    // full square area goes below
                    a += (double)squares[i][2] * (double)squares[i][2];
                } 
                else {
                    // partial square split by mid
                    a += x;   // area below mid
                    b += ((double)squares[i][2] * (double)squares[i][2]) - x; // area above mid
                }
            }
            else{
                // entire square lies above mid
                b += (double)squares[i][2] * (double)squares[i][2];
            }
        }
        // return areas below and above mid
        return {a, b};
    }

    double separateSquares(vector<vector<int>>& squares) {

        // find minimum possible y and maximum possible y
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < squares.size(); i++){
            // lowest bottom among all squares
            mini = min(mini, squares[i][1]);
            // highest top among all squares
            maxi = max(maxi, squares[i][1] + squares[i][2]);
        }

        // binary search range for answer
        double s = mini;
        double e = maxi;

        // binary search until precision is sufficient
        while(e - s > 1e-6){
            double mid = (s + e) / 2.0;

            // compute area split at mid
            pair<double,double> x = checkArea(mid, squares);

            // if below area is smaller, move up
            if(x.first < x.second) 
                s = mid;
            // otherwise move down
            else 
                e = mid;
        }

        // s converges to the y-coordinate where areas are equal
        return s;
    }
};
