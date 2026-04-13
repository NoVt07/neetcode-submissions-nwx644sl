class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(int num : st){
            if(!st.count(num-1)){
                int curnum = num;
                int curstreak = 1;
                while(st.count(curnum + 1)){
                    curnum++;
                    curstreak++;
                }
                longest = max(longest,curstreak);
            }
        }
        return longest;
    }
};
