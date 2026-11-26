class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();

        vector<pair<int, int>> myStack = {};
        // first -> rank
        // second -> height

        int maxi = 0;
        int height;
        int width;
        int lastI;

        for (int i = 0; i < n; i++) {
            //cout << "\n\ni = " << i << "\n";
            //cout << "height = " << heights[i] << "\n\n";
            lastI = -1;

            while (!myStack.empty() && myStack.back().second > heights[i]) {
                height = myStack.back().second;
                width = i - myStack.back().first;
                lastI = myStack.back().first;
                //cout << "pop : " << myStack.back().first << "\n";
                //cout << "height = " << height << "\n\n";
                //cout << "width = " << width << "\n\n";
                //cout << "score = " << height*width << "\n\n";

                
                maxi = max(maxi, height*width);

                myStack.pop_back();
            }
            if (lastI != -1) myStack.push_back({lastI, heights[i]});
            else myStack.push_back({i, heights[i]});

            //cout << "myStack : ";
            //for (auto [pos, x] : myStack) cout << "(" << pos << ", " << x << ") ";
            //cout << "\n";
        }
        return maxi;
        
    }
};