class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> pre = vector<int>(n, 0);
        vector<int> maxi = vector<int>(n, 0);
        vector<int> mini = vector<int>(n, 0);

        // pre[i] = somme de nums[0] à nums[i]
        // sum(i, j) = pre[j] - pre[i];

        // maxi[i] is the max in nums[i ... n-1]
        // mini[i] is the min in nums[0 ... i]

        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }

        maxi[n-1] = pre[n-1];
        mini[0] = 0;

        //for (int i = 0; i < n; i++) cout << pre[i] << " ";
        //cout << "\n\n";

        for (int i = n-2; i >= 0; i--) {
            maxi[i] = max(maxi[i+1], pre[i]);
        }
        for (int i = 1; i < n; i++) {
            mini[i] = min(mini[i-1], pre[i-1]);
        }

        //for (int i = 0; i < n; i++) cout << maxi[i] << " ";
        //cout << "\n\n";        

        //for (int i = 0; i < n; i++) cout << mini[i] << " ";
        //cout << "\n\n";        
        
        int output = max(nums[0],pre[n-1]);
        //cout << "initial output = " << output << "\n";
        for (int i = 0; i < n; i++) {
            output = max(output, maxi[i] - mini[i]);
        }

        return output;
    }
};
