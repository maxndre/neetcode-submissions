class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        std::unordered_map<int, int> present; // first int is the nums[i], the second is i

        for (int i = 0; i < n; i++) {
            if (present.contains(target - nums[i])) return {present[target - nums[i]], i};
            present[nums[i]] = i;
        }

        return {-1,-1};
    }
};
