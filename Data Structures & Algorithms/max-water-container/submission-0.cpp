class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0, right = heights.size() - 1;
        while(left < right){
            max_area = max(max_area, (right - left) * min(heights[left], heights[right]));
            if(heights[left] > heights[right]) right--;
            else left++;
        }
        return max_area;
    }
};
