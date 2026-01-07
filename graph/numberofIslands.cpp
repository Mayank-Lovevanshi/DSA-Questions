class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<char>>&grid)
    {
        grid[i][j] = '0';
        vector<vector<int>> pos = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int k=0;k<pos.size();k++)
            {
                int dx = i+pos[k][0];
                int dy = j+pos[k][1];
                if(isValid(dx,dy,grid))
                {
                    q.push({dx,dy});
                    grid[dx][dy] = '0';
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
