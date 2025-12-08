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
    void find(Node* root,int curr,int& left,int&right)
    {
        if(!root) return;
        left = min(curr,left);
        right = max(curr,right);
        find(root->left,curr-1,left,right);
        find(root->right,curr+1,left,right);
    }
    vector<int> topView(Node *root) {
        // code here
        if(!root) return {};
        int left=0,right=0;
        find(root,0,left,right);
        vector<int> ans(right-left+1);
        vector<bool> visited(right-left+1);
        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(left*-1);
        while(!q.empty())
        {
            Node* temp = q.front();
            int idx = index.front();
            q.pop();
            index.pop();
            if(!visited[idx])
            {
                visited[idx] = 1;
                ans[idx] = temp->data;
            }
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
