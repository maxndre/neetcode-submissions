vector<string> convert(vector<array<int,2>> map) {
    int n = map.size();
    vector<string> output = {};
    string line;
    for (array<int,2> queen : map) {
        line = string(queen[1], '.') + "Q" + string(n - queen[1] - 1, '.');
        output.push_back(line);
    }
    return output;
}



void AddAQueen(int n, int row, vector<array<int,2>>& map, vector<vector<array<int,2>>>& filled) {
    // we will add a queen on the row number "int row"
    // we will check if she fit in any of the lines
    bool wrong;
    for (int line = 0; line < n; line++) {
        // can the queen fit in (row, line)
        wrong = false;
        
        for (array<int, 2> queen : map) {
            // we check if the queen we already have in place are attacking {line, row}
            if (queen[1] == line || 
                queen[0] + queen[1] == row + line || 
                queen[0] - queen[1] == row - line) {

                // of so, we can't place a queen there
                wrong = true;
                break;
            }
        }
        if (wrong == false) {
            // if the queen can be placed here, let's go

            if (row == n-1) {
                // we placed the last queen, we can add it to the solution :
                map.push_back({row, line});
                filled.push_back(map);
                map.pop_back();
            } else {
                map.push_back({row, line});
                AddAQueen(n, row+1, map, filled);
                map.pop_back();
            }

        }
    }
}



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output = {};
        vector<vector<array<int,2>>> filled = {};

        vector<array<int,2>> map = {};

        AddAQueen(n, 0, map, filled);

        for (vector<array<int,2>> p : filled) {
            //for (auto x : p) cout << x[0] << " " << x[1] << "\n";
            //cout << "\n\n";
            output.push_back(convert(p));
        }




        return output;
        
    }
};
