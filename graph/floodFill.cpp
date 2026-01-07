class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>&image,int startColor)
    {
        int n = image.size();
        int m = image[0].size();
        if(i<0 || j<0 || i>=n || j>=m || image[i][j]!=startColor) return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<int>> &image,int color)
    {
        int startColor = image[i][j];
        image[i][j] = color;
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<int>> pos = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int k=0;k<pos.size();k++)
            {
                int dx = i+pos[k][0];
                int dy = j+pos[k][1];
                if(isValid(dx,dy,image,startColor))
                {
                    q.push({dx,dy});
                    image[dx][dy] = color;
                }
            }
        }
    }
    void dfs(int i,int j,vector<vector<int>> &image,int color,int startColor)
    {
        image[i][j] = color;
        vector<vector<int>> pos = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<pos.size();k++)
        {
            int dx = i+pos[k][0];
            int dy = j+pos[k][1];
            if(isValid(dx,dy,image,startColor))
            {
                dfs(dx,dy,image,color,startColor);
            }  
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        //bfs(sr,sc,image,color);
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};
