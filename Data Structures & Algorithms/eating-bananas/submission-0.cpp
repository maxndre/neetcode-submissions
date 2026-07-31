long long computeHour(vector<int>& piles, int bananas) {
    long long count = 0;

    for (int b : piles) {
        count += 1 + (b-1)/bananas;
    }

    return count;

}


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int lower = 1;
        int upper = std::ranges::max(piles);
        int center;
        long long hour;

        while (lower <= upper) {
            center = lower + (upper-lower)/2;

            hour = computeHour(piles, center);

            if (hour <= h) {
                upper = center - 1;
            } else if (hour > h) {
                lower = center + 1;
            } 


        }

        return lower;

    }
};
