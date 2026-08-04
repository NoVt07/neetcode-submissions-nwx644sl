class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        dfs(res, s, 0, 0, n);
        return res;
    }

private: 
    void dfs(vector<string>& res, string& s, int close, int open, int n) {
        if(s.length() == n*2){
            res.push_back(s);
            return;
        }
         
        if(open < n) {
            s.push_back('(');
            dfs(res, s, close, open + 1, n);
            s.pop_back();
        }
        if(close < open) {
            s.push_back(')');
            dfs(res, s, close + 1, open, n);
            s.pop_back();
        }
    }
};
