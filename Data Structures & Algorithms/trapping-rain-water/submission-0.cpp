class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left_to_right(n);
        vector<int> right_to_left(n);

        left_to_right[0] = height[0];
        right_to_left[n-1] = height[n-1];

        for (int i = 1; i < n-1; i++) {
            left_to_right[i] = max(left_to_right[i-1],height[i]);
            right_to_left[n-1-i] = max(right_to_left[n-1-i+1],height[n-1-i]);

        }

        vector<int> profil(n);

        int solution = 0;

        for (int i = 1; i < n-1; i++) {
            //cout << left_to_right[i] << " - " << right_to_left[i] << " - " << height[i] << " -> ";
            //cout << min(left_to_right[i],right_to_left[i]) - height[i] << "\n";
            solution += min(left_to_right[i],right_to_left[i]) - height[i];
        }

        return solution;


        
        
        
    }
};
