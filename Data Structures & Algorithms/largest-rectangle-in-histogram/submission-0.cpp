class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for(int i = 0; i <= n; i++){
            int c_h = (i == n) ? 0 : heights[i];

            while(!st.empty() && c_h < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width;

                if(st.empty()){
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                max_area = max(max_area, h*width);
            }
            st.push(i);
        }
        return max_area;
    }
};
