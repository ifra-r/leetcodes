// 94. Binary Tree Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        return inorderTraversal(root, res);
    }
    vector<int> inorderTraversal(TreeNode* root, vector<int> &res) {
        if (root == nullptr) return res;
        res = inorderTraversal(root->left, res);
        res.push_back(root->val);
        res = inorderTraversal(root->right, res);     
        return res;   
    }
};

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