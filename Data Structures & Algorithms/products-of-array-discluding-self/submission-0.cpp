class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //cout << n << "\n";
        vector<int> solution(n);
        vector<int> prefix_product(n); // prefix_product[i] = product from [0] to last [i]
        vector<int> suffix_product(n); // suffix_product[i] = product form [i] to [n-1]
        // -> solution[i] = prefix_product[i-1] * suffix_product[i+1]

        prefix_product[0] = nums[0]; 
        suffix_product[n-1] = nums[n-1];

        for (int i = 1; i < n-1; i++) {
            prefix_product[i] = prefix_product[i-1] * nums[i];
            suffix_product[n-1-i] = suffix_product[n-i] * nums[n-1-i];
        }

        solution[n-1] = prefix_product[n-2];
        //cout << "solution[0] = " << prefix_product[n-2] << "\n";
        solution[0] = suffix_product[1];
        //cout << "solution[n-1] = " << suffix_product[1] << "\n";

        for (int i = 1; i < n-1; i++) {
            //cout << "solution[" << i << "] = " << prefix_product[i-1] << " * " << suffix_product[i+1] << "\n";
            solution[i] = prefix_product[i-1] * suffix_product[i+1];
        }

        return solution;
    }
};
