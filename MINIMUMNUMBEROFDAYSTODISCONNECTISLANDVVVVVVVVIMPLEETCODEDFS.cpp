class Solution {
public:
    /*
Given a 2D grid consisting of 1s (land) and 0s (water).  An island is a maximal 4-directionally (horizontal or vertical)
 connected group of 1s.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

    */
    int par[900];
    int find(int x){
        if(par[x]==x)
            return x;
        return par[x] = find(par[x]);
    }
    
    bool merge(int x,int y){
        int a = find(x);
        int b = find(y);
        if(a==b) return false;
        par[a]=b;
        return true;
    }
    
    int dfs(vector<vector<int>> &g){
        int i,j,k,l,n=g.size();
        int m = g[0].size();
        int res=0;
        for(i=0;i<n*m;i++) par[i]=i;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                res+=g[i][j];
                if(g[i][j]==0) continue;
                if(i+1<n&&g[i+1][j]) res-=merge(i*m+j,(i+1)*m+j);
                if(j+1<m&&g[i][j+1]) res-=merge(i*m+j, i*m+(j+1));
            }
        }
        return res;
    }
    int minDays(vector<vector<int>>& grid) {
        if(dfs(grid)!=1) return 0;
        int i,j,k,l,n=grid.size(),m = grid[0].size();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    if(dfs(grid)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};