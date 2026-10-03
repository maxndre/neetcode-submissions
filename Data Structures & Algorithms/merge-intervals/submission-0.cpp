class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> output = {};

        vector<vector<int>> sortedIntervals = intervals;
        sort(sortedIntervals.begin(), sortedIntervals.end());

        //for (auto x : sortedIntervals) cout << x[0] << " " << x[1] << " -- ";
        //cout << "\n\n";

        //for (auto x : output) cout << x[0] << " " << x[1] << " -- ";
        //cout << "\n\n";

        output.push_back(sortedIntervals[0]);
        //cout << output[output.size()-1][0] << " " << output[output.size()-1][1] << "\n";
        int a, b;

        for (int i = 1; i < n; i++) {
            a = sortedIntervals[i][0];
            b = sortedIntervals[i][1];
            //cout << "a = " << a << " b = " << b << "\n";

            
            // we deal with intervals[i]
            if (a <= output[output.size()-1][1]) {
                output[output.size()-1][1] = max(output[output.size()-1][1], b);
                //cout << output[output.size()-1][0] << " " << output[output.size()-1][1] << " if \n";
            } else {
                output.push_back({a, b});
                //cout << output[output.size()-1][0] << " " << output[output.size()-1][1] << " else \n";
            }

            //for (auto x : output) cout << x[0] << " " << x[1] << " -- ";
            //cout << "\n\n";

        }

        return output;



        
    }
};
