#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> solution = {};
        int n = nums.size();
        if (n == 0) { return {}; }
        //for (int i = 0; i < n; i++) { cout << nums[i] << " "; }


        for (int target = 0; target < n - 2; target ++) {
            int below = target + 1;
            int above = n-1;

            if (target > 0 && nums[target] == nums[target - 1]) {
                continue; 
            }

            while (below < above && below < n-1 && above > 0) {
                int sum = nums[target] + nums[below] + nums[above];
                //cout << "we are at : " << target << " " << below << " " << above << "\n";
                //cout << "we are at " << below << " - " << above << "\n";

                if (sum > 0) {
                    //cout << "nums[below] + nums[above] > nums[target] \n";
                    above --;
                    
                } else if (sum < 0) {
                    //cout << "nums[below] + nums[above] < nums[target] \n";
                    below ++;

                    
                } else {
                    solution.push_back({nums[target],nums[below],nums[above]});

                    below++;
                    above--;
                    
                    while (below < above && nums[below] == nums[below - 1]) {
                        below++;
                    }

                    
                }           
            }
        }
        
        return solution;
    }
};

