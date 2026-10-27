void backtrack(int id, int k, const vector<int>& nums, unordered_map<int, int>& freq, vector<vector<int>>& output, vector<int>& current) {

    

    for (int i = 0; i < current.size(); i++) {
        cout << current[i] << " ";
    }
    cout << "\n";
    cout << "k = " << k << "\n";
    cout << "id = " << id << "\n";
    cout << "\n";
    cout << "\n";

    if (k+1 <= freq[nums[id]]) {
        current.push_back(nums[id]);

        output.push_back(current);
        backtrack(id, k+1, nums, freq, output, current);

        current.pop_back();
    }


    if (id+1 < nums.size()) {
        //current.push_back(nums[id+1]);
        backtrack(id+1, 0, nums, freq, output, current);
        //current.pop_back();
    }
}



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int, int> freq = {};
    vector<int> uniqueN = {};

    vector<int> seen(40);
    


    for (int i = 0; i < n; i++) {
        freq[nums[i]] = 0;
        if (!seen[nums[i]+20]) {
            seen[nums[i]+20] = true;
            uniqueN.push_back(nums[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        freq[nums[i]] += 1;
    }

    for (auto [a, b] : freq) {
        cout << a << " - " << b << "\n";
    }

    vector<int> current = {};
    vector<vector<int>> output = {};
    output.push_back({});


    backtrack(0, 0, uniqueN, freq, output, current);


    return output;






        
    }
};
