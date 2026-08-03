class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> check(nums.size(), false);

        dfs(res, cur, nums, check, 0);
        return res;
    }
private: 
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, vector<bool>& check, int idx) {
        if(idx == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0 ; i < nums.size(); i++) { 
            if(check[i] != true) {
                cur.push_back(nums[i]);
                check[i] = true;
                dfs(res, cur, nums, check, idx + 1);
                check[i] = false;
                cur.pop_back();
            }
        }
    }
};
