class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCheck[9][10] = {0};
        int colCheck[9][10] = {0};
        int boxCheck[9][10] = {0};

        for(int r = 0 ; r < 9; r++)
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;

                int num = board[r][c] - '0';
                int b = (r/3)*3 + (c/3);

                if(rowCheck[r][num] || colCheck[c][num] || boxCheck[b][num])
                    return false;

                rowCheck[r][num] = colCheck[c][num] = boxCheck[b][num] = 1;
            }
        return true;
    }
};
