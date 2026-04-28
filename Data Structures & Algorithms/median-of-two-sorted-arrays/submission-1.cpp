class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        
        while(left <= right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i;
            
            int maxLeftA = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightA = (i == m) ? INT_MAX : nums1[i];
            int maxLeftB = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightB = (j == n) ? INT_MAX : nums2[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if((m + n) % 2 == 0) {
                    int minright = min(minRightB, minRightA);
                    int maxleft = max(maxLeftA, maxLeftB);
                    return (double)(minright + maxleft) / 2.0;
                }
                else {
                    return max(maxLeftA, maxLeftB);
                }
            }
            else if(minRightA < maxLeftB) left = i + 1;
            else right = i - 1;
        }
        return 0.0;
    }
};
