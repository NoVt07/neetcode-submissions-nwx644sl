class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());

        if(n == 0) return 0;

        int ans = 1, temp = 1;
        for(int num : st){
            if(!st.count(num-1)){
                temp = 1;
            } else temp++;
            ans = max(ans, temp);
        }
        return ans;
    }
};
