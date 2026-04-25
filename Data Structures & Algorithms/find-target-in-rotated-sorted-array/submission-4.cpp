class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        if(nums[left] > nums[right]){
            int mid = 0;
            while(left < right){
                mid = (left + right) / 2;
                if(nums[mid] > nums[right]) left = mid + 1;
                if(nums[mid] <= nums[right]) right = mid;
            }
            cout << left << " " << right;
            if(nums[right] > target) return -1;
            if(nums[nums.size() - 1] < target){
                right--;
                left = 0;
            }
            else right = nums.size() - 1;
        } 
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
