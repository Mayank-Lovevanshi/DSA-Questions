/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    int height(Node* root)
    {
      if(!root) return 0;
      return 1+max(height(root->left),height(root->right));
    }
    void traverse(Node* root,vector<vector<int>>&ans,int left)
    {
        if(!root) return;
        ans[left].push_back(root->data);
        traverse(root->left,ans,left+1);
        traverse(root->right,ans,left);
    }
    vector<int> diagonal(Node *root) {
        // code here
        int size = height(root);
        vector<vector<int>> ans(size);
        traverse(root,ans,0);
        
        vector<int> temp;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
    }
};
