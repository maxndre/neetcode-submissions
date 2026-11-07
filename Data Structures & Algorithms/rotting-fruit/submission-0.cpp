



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int time = 0;

        pair<int, int> temp;


        queue<pair<int, int>> myQueue = {};

        int fresh = 0;
        int rotten;
        int newRottend = 0;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fresh += (grid[i][j] == 1);
                if (grid[i][j] == 2) {
                    myQueue.push({i, j});
                    newRottend++;
                }
            }
        }

        if (fresh == 0) return 0;


        int x, y;
        while (newRottend != 0) {
            time++;
            rotten = newRottend;
            newRottend = 0;
            for (int i = 0; i < rotten; i++) {
                // grid[x+1][y] is a rotten orange
                // 

                temp = myQueue.front();
                x = temp.first;
                y = temp.second;
                myQueue.pop();

                if (x+1 < m && grid[x+1][y] == 1) {
                    newRottend++;
                    fresh--;
                    myQueue.push({x+1, y});
                    grid[x+1][y] = 0;
                    
                } 
                if (x-1 >= 0 && grid[x-1][y] == 1) {
                    newRottend++;
                    fresh--;
                    myQueue.push({x-1, y});
                    grid[x-1][y] = 0;
                }
                if (y+1 < n && grid[x][y+1] == 1) {
                    newRottend++;
                    fresh--;
                    myQueue.push({x, y+1});
                    grid[x][y+1] = 0;
                }
                if (y-1 >= 0 && grid[x][y-1] == 1) {
                    newRottend++;
                    fresh--;
                    myQueue.push({x, y-1});
                    grid[x][y-1] = 0;
                }                                                
            }
        }

        if (fresh == 0) return time-1;
        else return -1;

        
    }
};