
int rob_line(vector<int>& nums, int retard) {
    int n = nums.size();

    int max_taking_i = max(nums[0+retard], nums[1+retard]);
    int max_leaving_i = nums[0+retard];


    int max_taking_i_copy;

    //cout << " === 1 === \n";
    //cout << "max_taking_i = " << max_taking_i << "\n";
    //cout << "max_leaving_i = " << max_leaving_i << "\n";

    for (int i = 2; i < n-1; i++) {
        max_taking_i_copy = max_taking_i;

        max_taking_i = max(nums[i+retard] + max_leaving_i, max_taking_i);
        max_leaving_i = max(max_leaving_i, max_taking_i_copy);


        //cout << " === " << i << " === \n";
        //cout << "max_taking_i = " << max_taking_i << "\n";
        //cout << "max_leaving_i = " << max_leaving_i << "\n";
    }

    return max_taking_i;


    
}









class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(rob_line(nums,0), rob_line(nums,1));

        
    }
};
