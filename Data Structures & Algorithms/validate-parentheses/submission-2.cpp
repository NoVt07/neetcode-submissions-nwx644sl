class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size(), i = 0;

        while(i < n){
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') st.push(s[i]);
            else {
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if(s[i] == '}' && c != '{') return false;
                if(s[i] == ')' && c != '(') return false;
                if(s[i] == ']' && c != '[') return false;
            }
            i++;
        }
        if(!st.empty())return false;
        return true;
    }
};
