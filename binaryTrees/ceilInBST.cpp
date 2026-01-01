class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        while(root)
        {
            if(root->data>x)
            {
                ceil = root->data;
                root = root->left;
            }
            else if(root->data==x)
            {
                ceil = root->data;
                break;
            }
            else root = root->right;
        }
        return ceil;
    }
};

