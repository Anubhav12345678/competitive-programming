


/*

Number of Closed Islands
User Accepted:1358
User Tried:1602
Total Accepted:1377
Total Submissions:2494
Difficulty:Medium
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed 
island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).



*/

class Solution {
public:
    bool vis[105][105];
    int closedIsland(vector<vector<int>>& grid) {
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        int n = grid.size();
        int m = grid[0].size();
        int i,j,k,l;
        queue<int > qx,qy;
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==0)
                {
                    vis[i][j]=1;
                    bool fg=1;
                    qx.push(i);
                    qy.push(j);
                    while(!qx.empty())
                    {
                        int cx = qx.front();
                        int cy = qy.front();
                        qx.pop();
                        qy.pop();
                        for(k=0;k<4;k++)
                        {
                            int nx = cx+dx[k];
                            int ny = cy+dy[k];
                            if(nx<0||ny<0||nx>=n||ny>=m) {
                                fg=0;
                                continue;
                            }
                            if(vis[nx][ny]||grid[nx][ny]==1)
                                continue;
                            qx.push(nx);
                            qy.push(ny);
                            vis[nx][ny]=1;
                        }
                    }
                    if(fg) ans++;
                    
                }
            }
        }
        return ans;
        
    }
};