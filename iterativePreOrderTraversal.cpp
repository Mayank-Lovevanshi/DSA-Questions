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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> traversalStack;
        if(!root) return ans;
        traversalStack.push(root);
        while(!traversalStack.empty())
        {
            TreeNode *temp = traversalStack.top();
            ans.push_back(temp->val);
            traversalStack.pop();
            if(temp->right) traversalStack.push(temp->right);
            if(temp->left) traversalStack.push(temp->left);
        }
        return ans;
    }
};
