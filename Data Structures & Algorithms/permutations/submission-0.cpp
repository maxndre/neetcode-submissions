void rec(vector<int>& nums, vector<bool>& mask, vector<int>& current,vector<vector<int>>& output) {
    int n = mask.size();

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (mask[i] == false) {
            flag = true;
            mask[i] = true;
            current.push_back(nums[i]);
            rec(nums, mask, current, output);
            current.pop_back();
            mask[i] = false;
        }
    }

    if (flag == false) {
        output.push_back(current);
    }
}



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output = {};

        vector<bool> mask(nums.size(), false);
        vector<int> current = {};

        rec(nums, mask, current, output);

        return output;
    }
};
