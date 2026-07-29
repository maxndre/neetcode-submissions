
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        int below = 0;
        int above = n-1;

        while (below < above || below < n-1 || above > 0) {
            //cout << "we are at " << below << " - " << above << "\n";

            if (numbers[below] + numbers[above] > target) {
                //cout << "numbers[below] + numbers[above] > target \n";
                above --;
                
            } else if (numbers[below] + numbers[above] < target) {
                //cout << "numbers[below] + numbers[above] < target \n";
                below ++;

                
            } else {
                return {below+1,above+1};
            }           
        }
        
        return {0,0};
    }
};

