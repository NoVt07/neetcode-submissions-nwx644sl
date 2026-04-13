class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;
        int total_water = 0;

        while(l < r){
            if(height[l] < height[r]){
                if(l_max < height[l]) l_max = height[l];
                else total_water += l_max - height[l];
                l++; 
            } else {
                if(r_max < height[r]) r_max = height[r];
                else total_water += r_max - height[r];
                r--;
            }
        }
        return total_water;
    }
};
