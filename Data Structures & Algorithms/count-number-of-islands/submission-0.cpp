class Solution {
private: 
    void dfs(vector<vector<char>>& grid, int c, int r) {
        int rows = grid.size();
        int cols = grid[0].size();
        if( r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0' ) return;
        grid[r][c] = '0';
        dfs(grid, c + 1, r);
        dfs(grid, c - 1, r);
        dfs(grid, c, r + 1);
        dfs(grid, c, r - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int countIsland = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    countIsland++;
                    dfs(grid, j, i);
                }
        return countIsland;
    }
};
