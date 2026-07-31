class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> left_to_right_min(n);
        vector<int> right_to_left_max(n);
        left_to_right_min[0] = prices[0];
        right_to_left_max[n-1] = prices[n-1];

        for (int i = 1; i < n; i++) {
            left_to_right_min[i] = min(left_to_right_min[i-1],prices[i]);
            right_to_left_max[n-1-i] = max(right_to_left_max[n-1-i+1],prices[n-1-i]);
        }

        int maxi = 0;

        for (int i = 1; i < n; i++) {
            if (right_to_left_max[i] - left_to_right_min[i] > maxi) {
                maxi = right_to_left_max[i] - left_to_right_min[i];
            }
        }

        return maxi;
        


    }
};
