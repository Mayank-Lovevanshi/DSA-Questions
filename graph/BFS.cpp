class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        vector<int> ans;
        q.push(0);
        int n = adj.size();
        vector<bool> visited(n,0);
        while(!q.empty())
        {
            while(!q.empty() && visited[q.front()])
            {
                q.pop();   
            }
            if(!q.empty())
            {
                int childrensOf = q.front();
                visited[childrensOf] = 1;
                ans.push_back(childrensOf);
                for(int i=0;i<adj[childrensOf].size();i++)
                {
                    q.push(adj[childrensOf][i]);
                }
            }
        }
        return ans;
    }
};
