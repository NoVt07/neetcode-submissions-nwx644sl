class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n,0);
        stack<int> st;
        stack<int> temp;

        for(int i = 0; i < n; i++){
            if(i < n - 1 && t[i] < t[i+1]) res[i] = 1;
            while(!st.empty()){
                if(t[i] > st.top()){
                    int x = temp.top(); temp.pop();
                    res[x] = i - x;
                    //cout << i << " " << x << endl;
                    st.pop();
                }
                else break;    
            }
            st.push(t[i]);
            temp.push(i);
        }
        return res;
    }
};
