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
    int find(unordered_map<int,int>&hm,int target)
    {
        return hm[target];
    }
    TreeNode* constructTree(vector<int>&pre,vector<int>&in,int start,int end,int index,unordered_map<int,int> &hm)
    {
        if(start>end) return nullptr;
        int pos = find(hm,pre[index]);
        TreeNode* root = new TreeNode(in[pos]);
        root->left = constructTree(pre,in,start,pos-1,index+1,hm);
        root->right = constructTree(pre,in,pos+1,end,index+pos-start+1,hm);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n  = inorder.size();
        unordered_map<int,int> hm;
        for(int i=0;i<n;i++)
        {
            hm[inorder[i]] = i;
        }
        return constructTree(preorder,inorder,0,n-1,0,hm);
    }
};
