class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int output = 0;

        vector<int> pre = {0};
        for (int i = 0; i < n; i++) pre.push_back(pre.back()+nums[i]);


        map<int, int> freqPre = {};
        for (int x : pre) freqPre[x]++;

        //for (int x : pre) cout << x << " ";
        //cout << "\n";
        //for (int x : pre) cout << x << " ";
        //cout << "\n";

        

        for (int i = 0; i < n; i++) {
            // we are at i, and we check how many pre[i]+k we have, we can make subarrays with i and those
            freqPre[pre[i]]--;
            output += freqPre[pre[i]+k];
            
        }

        return output;
               

        
    }
};