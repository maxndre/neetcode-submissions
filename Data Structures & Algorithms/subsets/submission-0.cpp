class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        vector<int> possible;
        int powerOfTwo;

        for (int mask = 0; mask < (1 << n); mask++) {
            //cout << "\n\nmask = " << mask << "\n";
            possible = {};
            powerOfTwo = 1;
            for (int i = 0; i < n; i++) {
                // cout << "i = " << i << " --- (1 << i) = " << (1 << i) << "\n";
                if ((mask >> i) % 2) {
                    possible.push_back(nums[i]);
                    //cout << "" << powerOfTwo << "\n";
                    powerOfTwo *= 2;
                }
                
            }
            output.push_back(possible);
        }

        return output;
    }    

};
