class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if(heights.empty()) return res;
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> tmp(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < cols; i++){
            q.push({0, i});
            tmp[0][i] = 1;
        }
        for(int i = 1; i < rows; i++) {
            q.push({i, 0});
            tmp[i][0] = 1;
        } 
        
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && tmp[nr][nc] == 0 && heights[nr][nc] >= heights[r][c]) {
                    tmp[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < cols; i++) {
            if (tmp[rows - 1][i] == 1) tmp[rows - 1][i] = 2; 
            else if (tmp[rows - 1][i] == 0) tmp[rows - 1][i] = -1; 
            q.push({rows - 1, i});
        }
        for(int i = 0; i < rows - 1; i++) { 
            if (tmp[i][cols - 1] == 1) tmp[i][cols - 1] = 2;
            else if (tmp[i][cols - 1] == 0) tmp[i][cols - 1] = -1;
            q.push({i, cols - 1});
        } 

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for(auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && heights[nr][nc] >= heights[r][c]) {
                    
                    if (tmp[nr][nc] == 1) { 
                        tmp[nr][nc] = 2;    
                        q.push({nr, nc});
                    } 
                    else if (tmp[nr][nc] == 0) { 
                        tmp[nr][nc] = -1;       
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        for(int i = 0; i < rows; i++) {  
            for(int j = 0; j < cols; j++) {
                if(tmp[i][j] == 2) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};