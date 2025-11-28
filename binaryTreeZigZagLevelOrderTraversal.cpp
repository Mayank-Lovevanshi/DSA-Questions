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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> traversalQueue;
        if(!root) return ans;
        traversalQueue.push(root);
        bool toggle = false;
        while(!traversalQueue.empty())
        {
            vector<int> temp;
            int size = traversalQueue.size();
            while(size--)
            {
                TreeNode *var = traversalQueue.front();
                if(var->left) traversalQueue.push(var->left);
                if(var->right) traversalQueue.push(var->right);
                temp.push_back(var->val);
                traversalQueue.pop();
            }
            if(!toggle)
            {
                toggle = true;
            }
            else
            {
                reverse(temp.begin(),temp.end());
                toggle = false;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
