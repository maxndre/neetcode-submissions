int explore(int num, int i, vector<int>& nums, map<array<int, 2>, int>& memo){
    if (memo.count({num, i}) != 0) return memo[{num, i}];
    if (i == nums.size()) return 0;
    if (nums[i] > num) {
        // max(we take it, we don't take it)
        //cout << i << " " << nums[i] << "\n";
        int output = max(explore(nums[i], i+1, nums, memo) + 1,explore(num, i+1, nums, memo));
        memo[{num, i}] = output; 
        return output;
    }

    int output = explore(num, i+1, nums, memo);
    memo[{num, i}] = output; 
    return output;
}




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        map<array<int, 2>, int> memo = {};
        return explore(-1000, 0, nums, memo);
    }
};



