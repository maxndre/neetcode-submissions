void mark(vector<vector<char>>& grid, array<int, 2> start) {
    int x = start[0];
    int y = start[1];
    int nx = grid.size();
    int ny = grid[0].size();

    grid[x][y] = '2';
    if (x+1 < nx && grid[x+1][y] == '1') {
        mark(grid, {x+1, y});
    }
    if (x-1 >= 0 && grid[x-1][y] == '1') {
        mark(grid, {x-1, y});
    }
    if (y+1 < ny && grid[x][y+1] == '1') {
        mark(grid, {x, y+1});
    }
    if (y-1 >= 0 && grid[x][y-1] == '1') {
        mark(grid, {x, y-1});
    }        
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<char>> markedGrid = grid;

        int nx = grid.size();
        int ny = grid[0].size();        

        for (int x = 0; x < nx; x++) {
            for (int y = 0; y < ny; y++) {
                if (markedGrid[x][y] == '1') {
                    //cout << x << " " << y << "\n"; 
                    mark(markedGrid, {x, y});

                    count ++;
                }
            }
        }

        return count;
        
    }
};

