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
                q.push(temp->left);
                trackParents[temp->left] = temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                trackParents[temp->right] = temp;
            }
        }
    }
    bool find(TreeNode* root,int start,TreeNode* &target)
    {
        if(!root) return false;
        if(root->val==start)
        {
            target = root;
            return true;
        }
        if(find(root->left,start,target) || find(root->right,start,target)) return true;
        return false;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> trackParents;
        TreeNode *target;
        markParents(root,trackParents);
        find(root,start,target);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        int curr = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty())
        {
            int size = q.size();
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
                if(trackParents[temp] && !visited[trackParents[temp]])
                {
                    q.push(trackParents[temp]);
                    visited[trackParents[temp]] = true;
                }
                
            }
            curr++;
        }
        return curr-1;
    }
};
