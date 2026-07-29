class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        array<int, 3> trois = {0,1,2};
        
        array<bool, 10> seen_1; 
        array<bool, 10> seen_2;

        for (int raw = 0; raw < 9; raw++) {
            seen_1 = {false};
            seen_2 = {false};
            for (int column = 0; column < 9; column++) {
                if (board[raw][column] != '.') {
                    if (seen_1[board[raw][column] - '1']) { return false; }
                    seen_1[board[raw][column] - '1'] = true;

                }

                if (board[column][raw] != '.') {
                    if (seen_2[board[column][raw] - '1']) { return false; }
                    seen_2[board[column][raw] - '1'] = true;
                }
            }
        }

        for (int a : trois) {
            for (int b : trois) {
                seen_1 = {false};

                for (int c : trois) {
                    for (int d : trois) {
                        if (board[3*a + c][3*b + d] != '.') {
                            if (seen_1[board[3*a + c][3*b + d] - '1']) { return false;}
                            seen_1[board[3*a + c][3*b + d] - '1'] = true;
                        }


                    }
                }
            }
        }


        return true;

        
    }
};


/*

["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]

*/