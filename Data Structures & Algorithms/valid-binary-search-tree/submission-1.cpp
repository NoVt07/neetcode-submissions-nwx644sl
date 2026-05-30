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
    bool check(TreeNode* root, long long min_val, long long max_val) {
        if(root == nullptr) return true;

        if(root->val <= min_val || root->val >= max_val) return false;

        bool check_left = check(root->left, min_val, root->val);
        bool check_right = check(root->right, root->val, max_val);

        return check_left && check_right;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};
