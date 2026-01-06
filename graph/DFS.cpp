class Solution {
  public:
    void DFS(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans)
    {
        visited[node] = 1;
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                DFS(adj[node][i],adj,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<bool> visited(adj.size(),0);
        DFS(0,adj,visited,ans);
        return ans;
    }
};
