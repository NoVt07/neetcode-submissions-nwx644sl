class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(128, -1);
        int n = s.size();
        if(n < 2) return n;
        int ans = 0;
        int l = 0;

        for(int i = 0; i < n; i++){
            
            if(index[s[i]] >= l){
                l = index[s[i]] + 1;
            }
            index[s[i]] = i;

            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
