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
    int find(int target,unordered_map<int,int>&hm)
    {
        return hm[target];
    }
    TreeNode* constructTree(vector<int>&post,vector<int>&in,int start,int end,int index,unordered_map<int,int> &hm)
    {
        if(start>end) return nullptr;
        int pos = find(post[index],hm);
        TreeNode* root = new TreeNode(in[pos]);
        root->right = constructTree(post,in,pos+1,end,index-1,hm);
        root->left = constructTree(post,in,start,pos-1,index-(end-pos)-1,hm);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hm;
        int n = postorder.size();
        for(int i=0;i<n;i++)
        {
            hm[inorder[i]] = i;
        }
        return constructTree(postorder,inorder,0,n-1,n-1,hm);
    }
};
