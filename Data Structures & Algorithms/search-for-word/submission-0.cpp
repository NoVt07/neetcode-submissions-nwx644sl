class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> check(rows, vector<bool>(cols, false));
        bool result = false;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0]) {
                    dfs(board, word, result, check, 0, i, j);
                    if(result == true) return true; 
                }
            }
        }
        return false;
    }

private:
    void dfs(vector<vector<char>>& board, string& word, bool& result, vector<vector<bool>>& check, int idx, int x, int y) {
        if(result == true) return;
        if(idx == word.length()){
            result = true;
            return;
        }
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if(check[x][y] == true) return;
        if(word[idx] != board[x][y]) return;
        check[x][y] = true;
        dfs(board, word, result, check, idx + 1, x - 1, y);
        dfs(board, word, result, check, idx + 1, x + 1, y); 
        dfs(board, word, result, check, idx + 1, x, y - 1); 
        dfs(board, word, result, check, idx + 1, x, y + 1); 
        check[x][y] = false;
    }
};