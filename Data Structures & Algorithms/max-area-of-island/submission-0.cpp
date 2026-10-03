





void mark(vector<vector<int>>& grid, array<int, 2> start, int& count) {
    int x = start[0];
    int y = start[1];
    int nx = grid.size();
    int ny = grid[0].size();

    grid[x][y] = 2;
    count++;
    if (x+1 < nx && grid[x+1][y] == 1) {
        mark(grid, {x+1, y}, count);
    }
    if (x-1 >= 0 && grid[x-1][y] == 1) {
        mark(grid, {x-1, y}, count);
    }
    if (y+1 < ny && grid[x][y+1] == 1) {
        mark(grid, {x, y+1}, count);
    }
    if (y-1 >= 0 && grid[x][y-1] == 1) {
        mark(grid, {x, y-1}, count);
    }    
    
}


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        int count;
        vector<vector<int>> markedGrid = grid;

        int nx = grid.size();
        int ny = grid[0].size();        

        for (int x = 0; x < nx; x++) {
            for (int y = 0; y < ny; y++) {
                if (markedGrid[x][y] == 1) {
                    //cout << x << " " << y << "\n"; 
                    count = 0;
                    mark(markedGrid, {x, y}, count);
                    maxCount = max(maxCount, count);

                    
                }
            }
        }

        return maxCount;
        
    }
};

