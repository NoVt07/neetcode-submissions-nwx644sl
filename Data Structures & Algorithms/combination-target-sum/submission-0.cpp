class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, nums, target, 0);
        return res;
    }

private: 
    void dfs(vector<vector<int>>& res,vector<int>& cur, vector<int>& nums, int target, int s) {
        if(target == 0){
            res.push_back(cur);
            return;
        }
        if(target < 0) return;
        for(int i = s; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(res, cur, nums, target - nums[i], i);
            cur.pop_back();
        }
    }
};
