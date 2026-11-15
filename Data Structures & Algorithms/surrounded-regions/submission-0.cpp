void explore(vector<vector<char>>& board, int x, int y) {
    //cout << "EXPLORE " << x << " " << y << "\n";
    int m = board.size();
    int n = board[0].size();   
    if (board[x][y] == 'O') {
        board[x][y] = 't';
    }

    if (x+1 < m && board[x+1][y] == 'O') {
        board[x+1][y] = 't';
        explore(board, x+1, y);
    }
    if (x-1 >= 0 && board[x-1][y] == 'O') {
        board[x-1][y] = 't';
        explore(board, x-1, y);
    }
    if (y+1 < n && board[x][y+1] == 'O') {
        board[x][y+1] = 't';
        explore(board, x, y+1);
    }
    if (y-1 >= 0 && board[x][y-1] == 'O') {
        board[x][y-1] = 't';
        explore(board, x, y-1);
    }
}



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') explore(board, i, 0);
            if (board[i][n-1] == 'O') explore(board, i, n-1);
        }
        for (int i = 1; i < n-1; i++) {
            if (board[0][i] == 'O') explore(board, 0, i);
            if (board[m-1][i] == 'O') explore(board, m-1, i);
        }

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                //cout << x << " " << y << " -> " << board[x][y] << "\n";
                if (board[x][y] == 'O') board[x][y] = 'X';
                if (board[x][y] == 't') board[x][y] = 'O';
            }
        }
    }
};