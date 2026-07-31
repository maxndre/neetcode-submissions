class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 1 && nums[0] == target) { return 0; }
        

        int lower = 0;
        int upper = n-1;
        int count = 0;
        

        while (lower < upper) {
            //cout << "lower = " << lower << " \n";
            //cout << "upper = " << upper << " \n";
            if (nums[lower/2 + upper/2] < target) {
                //cout << "upper \n";
                lower = (lower+upper)/2;
            } else if (nums[(lower+upper)/2] > target) {
                //cout << "lower \n";
                upper = (lower+upper)/2;
            } else {
                return (lower+upper)/2;
            }
            if (upper - lower <= 1) {
                if (nums[lower] == target) {
                    return lower;
                }
                if (nums[upper] == target) {
                    return upper;
                }
                break;
            }
        }
        //cout << lower << " - " << upper;
        return -1;


    }
};
