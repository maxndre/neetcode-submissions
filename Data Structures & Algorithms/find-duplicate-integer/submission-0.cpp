class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        int backup = 0;
        int counter = 0;

        while (fast != slow || fast == 0) {
            cout << slow << " - " << fast << "\n";
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        cout << "slow = 0; \n";

        while (fast != slow || fast == 0) {
            cout << slow << " - " << fast << "\n";
            fast = nums[fast];
            slow = nums[slow];
        }     

        cout << slow << " - " << fast << "\n";


        return slow;   







// slow -> 
// fast -> in the loop after i -> 

        
    }
};
