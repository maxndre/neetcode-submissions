class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(),nums.end());

        int maxi = 1;
        int streak = 1;

        for (int i = 1; i < n; i++) {
            //cout << "\n - nums[i] = " << nums[i] << "\n";
            if (nums[i-1] == nums[i]-1) {
                //cout << "streak++; \n";
                streak++;
                if (streak > maxi) {
                    //cout << "maxi = streak; \n";
                    maxi = streak;
                }
            } else if (nums[i-1] != nums[i]) {
                //cout << "streak = 0; \n";
                streak = 1;
            }
        }

        return maxi;
        
    }
};
