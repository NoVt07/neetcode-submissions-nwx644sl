class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int k = m * n;

        int left = 0, right = k - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int mid_i = mid / n, mid_j = mid % n;
            if(matrix[mid_i][mid_j] == target) return true;
            if(matrix[mid_i][mid_j] < target) left = mid + 1;
            if(matrix[mid_i][mid_j] > target) right = mid - 1;
        }
        return false;
    }
};
