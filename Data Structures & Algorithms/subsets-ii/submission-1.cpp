class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        
        sort(nums.begin(), nums.end());
        
        dfs(res, cur, nums, 0);
        return res;
    }

private: 
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        dfs(res, cur, nums, idx + 1);
        cur.pop_back(); 
        
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++; 
        }
        
        dfs(res, cur, nums, idx + 1);
    }
};