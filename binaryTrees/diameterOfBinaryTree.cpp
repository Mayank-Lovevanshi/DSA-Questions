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
    int calculateDiameter(TreeNode* root,int& maxHeight)
    {
        if(!root) return 0;
        int leftHeight = calculateDiameter(root->left,maxHeight);
        int rightHeight = calculateDiameter(root->right,maxHeight);
        maxHeight = max(leftHeight + rightHeight,maxHeight);
        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxHeight=0;
        calculateDiameter(root,maxHeight);
        return maxHeight;
    }
};
