
/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

    




*/





class Solution {
public:
    bool vis[55][55];
    int solve(vector<vector<int>> &g,int i,int j)
    {
        if(i<0||i>=g.size()||j<0||j>=g[0].size()||vis[i][j]||g[i][j]==0)
            return 0;
        vis[i][j]=1;
        return 1+solve(g,i+1,j)+solve(g,i-1,j)+solve(g,i,j+1)+solve(g,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i,j,k,l,n=grid.size();
        int m = grid[0].size();
        // bool vis[n][m];
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1)
                {
                    cnt=max(cnt,solve(grid,i,j));
                    // vis
                }
            }
        }
        return cnt;
    }
};