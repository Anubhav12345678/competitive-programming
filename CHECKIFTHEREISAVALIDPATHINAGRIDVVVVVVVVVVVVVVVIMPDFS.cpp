class Solution {
public:
    vector<vector<int> > g;
    int n,m;
    vector<vector<bool>> vis;
    bool isval(int i,int j){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(int x,int y){
        if(vis[x][y]) return ;
        vis[x][y]=1;
        int up=0;
        int down=0;
            int left=0;
        int right=0;
        if(g[x][y]==1)
            left=right=1;
        else if(g[x][y]==2)
            up=down=1;
        else if(g[x][y]==3)
            left=down=1;
        else if(g[x][y]==4)
            right=down=1;
        else if(g[x][y]==5)
            up=left=1;
        else up=right=1;
        
        if(up){
            int nx = x-1,ny=y;
            if(isval(nx,ny)&&(g[nx][ny]==2||g[nx][ny]==3||g[nx][ny]==4))
                dfs(nx,ny);
        }
        if(down){
           int nx = x+1,ny=y;
            if(isval(nx,ny)&&(g[nx][ny]==2||g[nx][ny]==5||g[nx][ny]==6))
                dfs(nx,ny);  
        }
        if(left){
             int nx = x,ny=y-1;
            if(isval(nx,ny)&&(g[nx][ny]==1||g[nx][ny]==4||g[nx][ny]==6))
                dfs(nx,ny);
        }
        if(right){
             int nx = x,ny=y+1;
            if(isval(nx,ny)&&(g[nx][ny]==1||g[nx][ny]==3||g[nx][ny]==5))
                dfs(nx,ny);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        g=grid;
        n=grid.size();
        m=grid[0].size();
        vis = vector<vector<bool>>(n,vector<bool>(m,0));
        dfs(0,0);
        return vis[n-1][m-1];
    }
};
/*
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a
 path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). 
 The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

*/