class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n-1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                //digits[i] == 9
                // we set it to 0 and go to the next one
                digits[i] = 0;
            }
        }

        vector<int> output = {1};
        for (int i = 0; i < n; i++) output.push_back(0);
        return output;

        

    }
};
