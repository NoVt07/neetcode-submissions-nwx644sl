class Solution {
public:
//code sau khi tối ưu 
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n,0);
        stack<int> st; // dùng 1 stack lưu index

        for(int i = 0; i < n; i++){
            while(!st.empty() && t[i] > t[st.top()]){
                
                int x = st.top(); st.pop();
                res[x] = i - x;
            }
            st.push(i);
        }
        return res;
    }
};
