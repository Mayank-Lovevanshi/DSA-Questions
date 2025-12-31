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
    void getPreOrder(TreeNode* root,vector<TreeNode*> &preorder)
    {
        if(!root) return;
        preorder.push_back(root);
        getPreOrder(root->left,preorder);
        getPreOrder(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> preorder;
        getPreOrder(root,preorder);
        int n = preorder.size();
        for(int i=1;i<n;i++)
        {
            root->left = nullptr;
            root->right = preorder[i];
            root = root->right;
        }
    }
};
