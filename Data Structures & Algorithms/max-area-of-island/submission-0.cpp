class Solution {
private: 
    int count = 0;
    void dfs(vector<vector<int>>& grid, int c, int r) {
        count++;
        int rows = grid.size();
        int cols = grid[0].size();
        if( r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 ){
            count--;
            return;
        }
        grid[r][c] = 0;
        dfs(grid, c + 1, r);
        dfs(grid, c - 1, r);
        dfs(grid, c, r + 1);
        dfs(grid, c, r - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int max = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1){
                    dfs(grid, j, i);
                    if(max < count)max = count;
                    count = 0;
                }
        return max;
    }
};

