void takeItAndLeaveIt(vector<int>& candidates, int target, int step, vector<int>& path, vector<vector<int>>& output) {

    if (target == 0) {
        output.push_back(path);
        return;
    }

    if (step == candidates.size() || target < candidates[step]) {
        return;
    }
    

    path.push_back(candidates[step]);
    takeItAndLeaveIt(candidates, target-candidates[step], step+1, path, output);
    path.pop_back();

    int numberCopies = 0;
    while (step + numberCopies < candidates.size() && candidates[step + numberCopies] == candidates[step]) numberCopies++;
    takeItAndLeaveIt(candidates, target, step+numberCopies, path, output);

}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output = {};
        vector<int> path = {};

        takeItAndLeaveIt(candidates, target, 0, path, output);

        return output;
    }
};


