








class Solution {
public:

    vector<vector<int>> output;

    void takeItAndLeaveIt(vector<int>& nums, int target, const vector<int>& current, int id) {
        int currentSum = 0;
        for (int u : current) currentSum += u;

        if (currentSum == target) {
            output.push_back(current);
            return;
        }


        if (currentSum + nums[id] <= target) { // if current can hold nums[id]
            vector<int> biggerCurrent = current;
            biggerCurrent.push_back(nums[id]);
            takeItAndLeaveIt(nums, target, biggerCurrent, id);
        }

        if (id < nums.size()-1) takeItAndLeaveIt(nums, target, current, id+1);


    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return {};
        output = {};

        takeItAndLeaveIt(nums, target, {}, 0);

        return output;
        
    }
};
