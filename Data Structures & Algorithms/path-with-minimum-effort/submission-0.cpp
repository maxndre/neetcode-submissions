bool valid(int x, int y, int m, int n) {
    if (x < 0 || y < 0) return false;
    else if (x >= m || y >= n) return false;
    else return true;
}


class Solution {
public:

    vector<pair<int, int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        //cout << "m = " << m << " -- n = " << n << "\n";
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > myQueue = {};

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        myQueue.push({0, {0,0}});

        int maxi = 0;

        int height;
        int x;
        int y;

        while (!myQueue.empty()) {
            auto elem = myQueue.top();
            myQueue.pop();
            height = elem.first;
            x = elem.second.first;
            y = elem.second.second;

            if (seen[x][y]) continue;
            seen[x][y] = true;



            //cout << "\n\n(" << x << ", " << y << ") maxi{" << maxi << "}\n";
            //cout << "diff = " << height << " heights = " << heights[x][y] << "\n";
            maxi = max(maxi, height);
            if (x == m-1 && y == n-1) {
                return maxi;
            }
            
            for (auto [dx, dy] : d) {
                if (valid(x+dx, y+dy, m, n) && !seen[x+dx][y+dy]) {
                    myQueue.push({abs(heights[x][y] - heights[x+dx][y+dy]), {x+dx, y+dy}});


                    //cout << "\nx+dx = " << (x+dx) << "\n";
                    //cout << "y+dy = " << (y+dy) << "\n";
                    //cout << "heights[x+dx][y+dy] = " << heights[x+dx][y+dy] << "\n";
                    //cout << "heights[x][y] = " << heights[x][y] << "\n";
                    //cout << "added : " << abs(heights[x][y] - heights[x+dx][y+dy]) << " (" << (x+dx) << ", " << (y+dy) << ") [" << heights[x+dx][y+dy] << "]\n";
                }
            }
        }

        //cout << "???\n";
        return maxi;


//[4, 3,4 ,10,5 ,5,9,2],
//[10,8,2 ,10,9 ,7,5,6],
//[5 ,8,10,10,10,7,4,2],
//[5 ,1,3 ,1 ,1 ,3,1,9],
//[6 ,4,10,6 ,10,9,4,6]



//[[10,8],
// [10,8],
// [1 ,2],
// [10,3],
// [1 ,3],
// [6 ,3],
// [5 ,2]]
        
    }
};