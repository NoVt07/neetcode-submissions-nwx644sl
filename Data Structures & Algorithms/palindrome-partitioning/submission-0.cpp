class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        
        dfs(res, cur, s, 0);
        return res;
    }

private:
    void dfs(vector<vector<string>>& res, vector<string>& cur, string& s, int idx) {
        if (idx == s.length()) {
            res.push_back(cur);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                cur.push_back(s.substr(idx, i - idx + 1));
                dfs(res, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};