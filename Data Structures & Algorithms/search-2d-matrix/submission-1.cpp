class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

        int top = 0, bot = col - 1;
        while(top < row && bot >= 0) {
            if(matrix[top][bot] == target) return true;
            else if(matrix[top][bot] < target) top++;
            else bot--;
        }
        return false;
    }
};
