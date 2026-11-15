class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        

        int pos = 0;
        int newPos = 0;
        int jump = 0;
        int maxi = 0;
        while (pos < n-1) {
            //cout << "\npos = " << pos << "\n";
            //cout << "jump = " << jump << "\n";
            // here we are in pos, we made jump jump
            maxi = 0;

            for (int i = pos; i <= pos+nums[pos] && i < n; i++) {
                if (i == n-1) return jump+1;
                if (maxi < i+nums[i]) {
                    maxi = i+nums[i];
                    newPos = i;
                }
            }
            
            pos = newPos;
            jump++;
            //cout << "pos = " << pos << "\n";
        }
        //cout << "\n\npos = " << pos << "\n";
        return jump;
    }
};
