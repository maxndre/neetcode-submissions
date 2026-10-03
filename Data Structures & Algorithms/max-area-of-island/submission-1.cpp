void mark(const vector<vector<int>>& grid, vector<vector<bool>>& seen, int x, int y, int& count) {
    int nx = seen.size();
    int ny = seen[0].size();

    seen[x][y] = true;
    count++;
    if (x+1 < nx && !seen[x+1][y] && grid[x+1][y] == 1) {
        mark(grid, seen, x+1, y, count);
    }
    if (x-1 >= 0 && !seen[x-1][y] && grid[x-1][y] == 1) {
        mark(grid, seen, x-1, y, count);
    }
    if (y+1 < ny && !seen[x][y+1] && grid[x][y+1] == 1) {
        mark(grid, seen, x, y+1, count);
    }
    if (y-1 >= 0 && !seen[x][y-1] && grid[x][y-1] == 1) {
        mark(grid, seen, x, y-1, count);
    }    
    
}


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        int count;
        int nx = grid.size();
        int ny = grid[0].size(); 

        vector<vector<bool>> seen = vector(nx, vector(ny, false));

       

        for (int x = 0; x < nx; x++) {
            for (int y = 0; y < ny; y++) {
                if (!seen[x][y] && grid[x][y] == 1) {
                    //cout << x << " " << y << "\n"; 
                    count = 0;
                    mark(grid, seen, x, y, count);
                    maxCount = max(maxCount, count);

                    
                }
            }
        }

        return maxCount;
        
    }
};

