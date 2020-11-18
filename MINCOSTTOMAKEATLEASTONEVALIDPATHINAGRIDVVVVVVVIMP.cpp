/*
Given a m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in 
this cell. The sign of grid[i][j] can be:
1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some invalid signs on the cells of the grid which points outside the grid.

You will initially start at the upper left cell (0,0). A valid path in the grid is a path which starts from the upper left 
cell (0,0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path doesn't have to
 be the shortest.


You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

 

Example 1:


Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with
 cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with
 s cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.

*/
#define ff first
#define se second
class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>> &g,vector<vector<int>> &dp,int r,int c,int cost,queue<pair<int,int>> &q)
    {
        int n = g.size();
        int m = g[0].size();
        if(r<0||r>=n||c<0||c>=m||dp[r][c]!=INT_MAX) return;
        dp[r][c]=cost;
        q.push({r,c});
        int nextdir = g[r][c]-1;
        dfs(g,dp,r+dir[nextdir][0],c+dir[nextdir][1],cost,q);
    }
    int minCost(vector<vector<int>>& grid) {
        int i,j,k,l,n=grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        dfs(grid,dp,0,0,0,q);
        int cost=0;
        while(!q.empty()){
            int sz = q.size();
            cost++;
            for(i=0;i<sz;i++){
                auto cor = q.front();
                q.pop();
                int x = cor.first;
                int y=  cor.second;
                // dp[x][y] = cost;
                for(j=0;j<4;j++)
                    dfs(grid,dp,x+dir[j][0],y+dir[j][1],cost,q);
            }
        }
        
        return dp[n-1][m-1];
            
            
        }
};