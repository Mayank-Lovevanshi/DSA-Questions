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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        stack<bool> visited;
        vector<int> ans;
        if(!root) return ans;
        st.push(root);
        visited.push(false);
        while(!st.empty())
        {
            bool status = visited.top();
            TreeNode *temp = st.top();
            visited.pop();
            st.pop();
            if(status)
            {
                ans.push_back(temp->val);
            }
            else
            {
                if(temp->right)
                {
                    st.push(temp->right);
                    visited.push(false);
                }
                st.push(temp);
                visited.push(true);
                if(temp->left)
                {
                    st.push(temp->left);
                    visited.push(false);
                }
            }
        }
        return ans;
    }
};
