class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int bestDeal = 0;
        int minPrice = prices[0];

        for (int i = 1; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 

            if (prices[i] - minPrice > bestDeal) {
                bestDeal = prices[i] - minPrice;
            }
        }
        
        return bestDeal;
        


    }
};
