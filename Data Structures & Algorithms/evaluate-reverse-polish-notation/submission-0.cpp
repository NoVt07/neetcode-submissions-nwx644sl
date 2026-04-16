class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(const string&x : tokens){
            if(x == "+" || x == "-" || x == "*" || x == "/"){
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                if(x == "+") st.push(a + b);
                if(x == "-") st.push(a - b);
                if(x == "*") st.push(a * b);
                if(x == "/") st.push(a / b);
            } else {
                st.push(stoi(x));
            }
        }
        return (long long)st.top();
    }
};
