class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = 0;
        for(int i = 0; i < nums.size(); ++i) {
            t += nums[i];
        }
        if(t % 2 == 1) return false;

        vector<int> dp(t/2 + 1, 0);
        dp[0] = 1;

        for(int num : nums) {
            for(int i = t/2; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }
        return dp[t/2] == 0 ? false : true;
    }
};
