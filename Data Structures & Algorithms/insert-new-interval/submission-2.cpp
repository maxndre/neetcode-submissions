class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        if (intervals.size() == 1) {
            vector<int> merged = {min(intervals[0][0], newInterval[0]), max(intervals[0][1], newInterval[1])};
            if (intervals[0][0] <=  newInterval[0] && newInterval[0] <= intervals[0][1]) return {merged};
            if (intervals[0][0] <=  newInterval[1] && newInterval[1] <= intervals[0][1]) return {merged};
            if (newInterval[0] <=  intervals[0][0] && intervals[0][0] <= newInterval[1]) return {merged};
            if (newInterval[0] <=  intervals[0][1] && intervals[0][1] <= newInterval[1]) return {merged};

            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            return intervals;
        }
        int n = intervals.size();
        //cout << n << "\n";
        int l = newInterval[0];
        int r = newInterval[1];

        int left = 1;
        int right = n-2;

        

        while (left < n && !(intervals[left-1][1] < l && l <= intervals[left][1])) {
            //cout << "\nintervals[left-1][1] = " << intervals[left-1][1] << "\n";
            //cout << "l = " << l << "\n";
            //cout << "intervals[left][1] = " << intervals[left][1] << "\n";
            left++;
            //cout << "left++;\n";

        }
        while (right > 0 && !(intervals[right][0] <= r && r < intervals[right+1][0])){
            //cout << "\nintervals[right][0] = " << intervals[right][0] << "\n";
            //cout << "r = " << r << "\n";
            //cout << "intervals[right+1][0] = " << intervals[right+1][0] << "\n";
            right--;
            //cout << "right--;\n"; 
            }

        //cout << left << " " << right << "\n";

        

        if (l <= intervals[0][1]) left = 0;
        if (intervals[n-1][0] <= r) right = n-1;

        if (r < intervals[0][0]) {
            intervals.push_back(intervals[n-1]);
            for (int i = n-1; i >= 0; i--) {
                intervals[i+1] = intervals[i];
            }
            intervals[0] = newInterval;
            return intervals;
        }

        if (l > intervals[n-1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        //cout << "\nintervals[n-1][0] = " << intervals[n-1][0] << "\n";
        //cout << "r = " << r << "\n";
        //cout << "intervals[n-1][1] = " << intervals[n-1][1] << "\n";

        //cout << left << " " << right << "\n";
        


        vector<int> merged = vector<int>(2);
        merged[0] = min(intervals[left][0], l);
        merged[1] = max(intervals[right][1], r);
        
        
        if (right == left) {
            
            intervals[right][0] = merged[0];
            intervals[right][1] = merged[1];
            
            
            return intervals;
        }
        if (right < left) {
            // we need to add merged in the middle of intervals
            intervals.push_back(intervals[n-1]);
            for (int i = n-1; i >= left; i--) {
                intervals[i+1] = intervals[i];
            }
            intervals[left] = merged;
            return intervals;
        }

        if (left < right) {
            int diff = right - left;
            intervals[left] = merged;
            for (int i = left+1; i+diff < n; i++) {
                intervals[i] = intervals[i+diff];
            }
            for (int i = 0; i < diff; i++) intervals.pop_back();
            return intervals;
        }

        return intervals;



    }
};
