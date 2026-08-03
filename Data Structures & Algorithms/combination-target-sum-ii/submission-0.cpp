class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(res, cur, candidates, target, 0, 0);
        return res;
    }

private: 
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target, int idx, int check) {
        if(target == 0) res.push_back(cur);
        if(target <= 0) return;

        for(int i = idx; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            if(candidates[i] != check) {
               
                dfs(res, cur, candidates, target - candidates[i], i + 1, check);
            }
            check = cur.back();
            cur.pop_back();
        }
    }
};
