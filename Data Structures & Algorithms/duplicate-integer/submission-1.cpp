class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> present;


        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //cout << "i = " << i << "\nnums[i] = " << nums[i] << "\n";
            if (present.count(nums[i]) == 0) {
                present[nums[i]] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};