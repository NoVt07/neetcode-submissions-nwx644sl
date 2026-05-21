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
    void dfs(TreeNode* root, int depth, vector<vector<int>>& result) {
        if(!root) return;

        if(depth == result.size()) result.push_back({});

        result[depth].push_back(root->val);

        dfs(root->left, depth + 1, result);
        dfs(root->right, depth + 1, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> curr;
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            result.push_back(curr);

        }
        return result;
    }
};
