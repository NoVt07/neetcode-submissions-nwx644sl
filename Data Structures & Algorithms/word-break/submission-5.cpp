class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        int maxLength = 0;
        for(const string words : wordDict) {
            maxLength = max(maxLength, (int)words.length());
        }

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++)
            for(int j = i - 1; j >= max(0, i - maxLength); j--) 
                if(dp[j] && wordset.find(s.substr(j, i - j)) != wordset.end()) {
                    dp[i] = true;
                    break;
                }
        return dp[n];
    }
};
