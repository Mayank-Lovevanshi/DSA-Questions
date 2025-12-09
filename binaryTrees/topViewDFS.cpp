/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void find(Node* root,int& left,int& right,int curr)
    {
        if(!root) return;
        left = min(left,curr);
        right = max(right,curr);
        find(root->left,left,right,curr-1);
        find(root->right,left,right,curr+1);
    }
    void view(Node* root,vector<int> &ans,vector<int> &level,int curr,int lvl)
    {
        if(!root) return;
        if(lvl<level[curr])
        {
            level[curr] = lvl;
            ans[curr] = root->data;
        }
        view(root->left,ans,level,curr-1,lvl+1);
        view(root->right,ans,level,curr+1,lvl+1);
    }
    vector<int> topView(Node *root) {
        // code here
        int left=0,right=0;
        find(root,left,right,0);
        vector<int> ans(right-left+1);
        vector<int> level(right-left+1,INT_MAX);
        view(root,ans,level,-1*left,0);
        return ans;
    }
};
