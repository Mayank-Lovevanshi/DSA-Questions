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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            bool pushed = false;
            while(size--)
            {
                TreeNode* temp = q.front();
                if(!pushed)
                {
                    ans.push_back(temp->val);
                    pushed = true;
                }
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                q.pop();
            }
        }
        return ans;
    }
};
