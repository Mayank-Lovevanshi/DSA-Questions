/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &trackParents)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
            {
                trackParents[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                trackParents[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> trackParent;
        markParents(root,trackParent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(currLevel++==k) break;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(trackParent[temp] && !visited[trackParent[temp]])
                {
                    q.push(trackParent[temp]);
                    visited[trackParent[temp]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};
