class Solution {
public:
    int func(vector<bool> & visited)
    {
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i]) return i;
        }
        return -1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,0);
        queue<int> q;
        int prov = 0;
        int node;
        while((node=func(visited))!=-1)
        {
            prov++;
            visited[node] = 1;
            q.push(node);
            while(!q.empty())
            {
                node = q.front();
                q.pop();
                for(int i=0;i<n;i++)
                {
                    if(isConnected[node][i]==1 && !visited[i])
                    {
                        visited[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        return prov;
    }
};
