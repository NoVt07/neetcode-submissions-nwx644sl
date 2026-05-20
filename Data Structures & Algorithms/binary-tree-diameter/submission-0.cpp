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
    int max_diameter = 0;

    int cD(TreeNode* root) {
        if(root == nullptr) return 0;

        int lD = cD(root->left);
        int rD = cD(root->right);

        max_diameter = max(max_diameter, lD + rD);
        return max(lD, rD) + 1;        
   }

    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        cD(root);
        return max_diameter;
    }
};
