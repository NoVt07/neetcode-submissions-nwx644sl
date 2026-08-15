class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void markSafe(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();
        
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
            return;
        }
        
        board[r][c] = 'T';
        
        for (auto d : dir) {
            markSafe(board, r + d[0], c + d[1]);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') markSafe(board, i, 0);               
            if (board[i][cols - 1] == 'O') markSafe(board, i, cols - 1); 
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') markSafe(board, 0, j);               
            if (board[rows - 1][j] == 'O') markSafe(board, rows - 1, j); 
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};