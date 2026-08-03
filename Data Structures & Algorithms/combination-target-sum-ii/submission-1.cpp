class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(res, cur, candidates, target, 0);
        return res;
    }

private: 
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) break; 
            
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            
            cur.push_back(candidates[i]);
            dfs(res, cur, candidates, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }
};