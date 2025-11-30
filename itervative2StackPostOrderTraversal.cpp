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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        stack<bool> visited;
        vector<int> ans;
        if(!root) return ans;
        st.push(root);
        visited.push(false);
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            bool status = visited.top();
            st.pop();
            visited.pop();
            if(status)
            {
                ans.push_back(temp->val);
            }
            else
            {
                st.push(temp);
                visited.push(true);
                if(temp->right)
                {
                    st.push(temp->right);
                    visited.push(false);
                }
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
