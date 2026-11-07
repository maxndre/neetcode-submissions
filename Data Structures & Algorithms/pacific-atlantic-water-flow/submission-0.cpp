void explore(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& ocean) {
    int m = heights.size();
    int n = heights[0].size();   
    if (x+1 < m && heights[x][y] <= heights[x+1][y] && !ocean[x+1][y]) {
        //cout << x << " " << y << " --> " << (x+1) << " " << (y) << "\n";
        ocean[x+1][y] = true;
        explore(heights, x+1, y, ocean);     
    }
    if (x-1 >= 0 && heights[x][y] <= heights[x-1][y] && !ocean[x-1][y]) {
        //cout << x << " " << y << " --> " << (x-1) << " " << (y) << "\n";
        ocean[x-1][y] = true;
        explore(heights, x-1, y, ocean);     
    }
    if (y+1 < n && heights[x][y] <= heights[x][y+1] && !ocean[x][y+1]) {
        //cout << x << " " << y << " --> " << (x) << " " << (y+1) << "\n";
        ocean[x][y+1] = true;
        explore(heights, x, y+1, ocean);     
    }
    if (y-1 >= 0 && heights[x][y] <= heights[x][y-1] && !ocean[x][y-1]) {
        //cout << x << " " << y << " --> " << (x) << " " << (y-1) << "\n";
        ocean[x][y-1] = true;
        explore(heights, x, y-1, ocean);     
    }
}






class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            pacific[0][i] = true;
            //cout << " === === PACFIC === === \n";
            explore(heights, 0, i, pacific);
            atlantic[m-1][i] = true;
            //cout << " === === ATLANTIC === === \n";
            explore(heights, m-1, i, atlantic);
        }

        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            //cout << " === === PACFIC === === \n";
            explore(heights, i, 0, pacific);
            atlantic[i][n-1] = true;
            //cout << " === === ATLANTIC === === \n";
            explore(heights, i, n-1, atlantic);
        }

        vector<vector<int>> output = {};
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (atlantic[x][y] && pacific[x][y]) {
                    output.push_back({x, y});
                }
            }
        }

        return output;

    }
};
