class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int max_taking_i = max(nums[0], nums[1]);
        int max_leaving_i = nums[0];


        int max_taking_i_copy;

        cout << " === 1 === \n";
        cout << "max_taking_i = " << max_taking_i << "\n";
        cout << "max_leaving_i = " << max_leaving_i << "\n";

        for (int i = 2; i < n; i++) {
            max_taking_i_copy = max_taking_i;

            max_taking_i = max(nums[i] + max_leaving_i, max_taking_i);
            max_leaving_i = max(max_leaving_i, max_taking_i_copy);


            cout << " === " << i << " === \n";
            cout << "max_taking_i = " << max_taking_i << "\n";
            cout << "max_leaving_i = " << max_leaving_i << "\n";
        }

        return max_taking_i;


        
    }
};
