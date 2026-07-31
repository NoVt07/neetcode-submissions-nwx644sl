/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root, int& max_sum) {
        if(root == nullptr) return 0;

        int left_max = max(0 , dfs(root->left, max_sum));
        int right_max = max(0, dfs(root->right, max_sum));

        int cur_max = root->val + left_max + right_max;
        max_sum = max(max_sum, cur_max);

        return root->val + max(left_max, right_max);
    }

    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }
};
