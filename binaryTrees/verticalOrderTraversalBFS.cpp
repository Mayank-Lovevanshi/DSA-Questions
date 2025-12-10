/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void find(Node* root,int curr,int& left,int& right)
    {
        if(!root) return;
        left = min(left,curr);
        right = max(right,curr);
        find(root->left,curr-1,left,right);
        find(root->right,curr+1,left,right);
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        int left=0,right=0;
        find(root,0,left,right);
        vector<vector<int>> ans(right-left+1);
        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(-1*left);
        while(!q.empty())
        {
            Node* temp = q.front();
            int idx = index.front();
            q.pop();
            index.pop();
            ans[idx].push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
                index.push(idx-1);
            }
            if(temp->right)
            {
                q.push(temp->right);
                index.push(idx+1);
            }
        }
        return ans;
    }
};
