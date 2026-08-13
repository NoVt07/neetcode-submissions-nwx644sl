class Solution {
private:
    int maxgrid(vector<vector<int>>& grid) {
        int m = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) return -1;
                if(m < grid[i][j]) m = grid[i][j];
            }
        return m == 0 ? m : m - 2;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == 2) q.push({i, j});
        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= rows || nr < 0 || nc >= cols || nc < 0 || grid[nr][nc] == 0) continue;
                if(grid[nr][nc] == 1) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return maxgrid(grid);
    }
};
