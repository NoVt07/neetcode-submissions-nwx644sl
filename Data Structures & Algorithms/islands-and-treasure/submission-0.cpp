class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }
private:
    void bfs(vector<vector<int>>& grid) {
        if(grid.empty() && grid[0].empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();
        const int INF = 2147483647;
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)     
                if(grid[i][j] == 0 ) q.push({i,j});
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1]; 
                if(nr >= rows || nr < 0 || nc >= cols || nc < 0 || grid[nr][nc] != INF) continue;
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
