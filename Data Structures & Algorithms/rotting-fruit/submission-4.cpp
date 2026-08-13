class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0; 
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh_count++;
            }
        }
        int time = 0; 
        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                    
                    fresh_count--;
                    time = max(time, grid[nr][nc] - 2); 
                }
            }
        }
        return fresh_count > 0 ? -1 : time;
    }
};
