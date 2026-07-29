class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        std::map<int,int> count = {};

        for (int i : nums) { // we compute the historygram 
            count[i]++;
        } 

        vector<array<int, 2>> count_pairs = {};
        for (auto& [key, value] : count) { // we create a set 
            count_pairs.push_back({key,value});
        }

        sort(count_pairs.begin(),count_pairs.end(),[](array<int, 2> a, array<int, 2> b){ return a[1] > b[1]; });
        
        vector<int> solution = {};

        for (int i = 0; i < k; i++) {
            solution.push_back(count_pairs[i][0]);
        }

        return solution;
    }
};
