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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> traversalQueue;
        if(!root) return ans;
        traversalQueue.push(root);
        while(!traversalQueue.empty())
        {
            vector<int> temp;
            int size = traversalQueue.size();
            while(size--)
            {
                TreeNode *var = traversalQueue.front();
                traversalQueue.pop();
                if(var->left) traversalQueue.push(var->left);
                if(var->right) traversalQueue.push(var->right);
                temp.push_back(var->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
