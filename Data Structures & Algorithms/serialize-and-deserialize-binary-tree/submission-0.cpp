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

class Codec {
private:

    TreeNode* build(queue<string>& q){
        string cur = q.front();
        q.pop();
        
        if(cur == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(cur));

        root->left = build(q);
        root->right = build(q);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "N,";
        string cur = to_string(root->val) + ",";
        return cur + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        queue<string> q;

        while(getline(ss,token,',')) q.push(token);

        return build(q);
    }
};
