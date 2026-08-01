class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int lower = 0;
        int upper = n-1;
        int center;

        if (nums[lower] < nums[upper]) {
            return nums[lower];
        }

        while (lower < upper) {
            center = lower + (upper - lower)/2;
            
            if (nums[center] >= nums[upper]) { // we are before the jump
                lower = center + 1;

            } else { // we are after the jump
                upper = center;
            }

        }

        return nums[lower];
        
    }
};
