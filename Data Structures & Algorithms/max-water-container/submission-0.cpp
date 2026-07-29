class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int below = 0;
        int above = n-1;

        int maximum = 0;

        while (below < above) {
            //cout << below << " - " << above << "\n";
            //cout << min(heights[below], heights[above]) * (above - below) << "\n \n";
            if (min(heights[below], heights[above]) * (above - below) > maximum) {
                maximum = min(heights[below], heights[above]) * (above - below);
            }

            if (heights[below] < heights[above]) {
                below ++;
            } else {
                above --;
            }
        }
    
    return maximum;


    }
};
