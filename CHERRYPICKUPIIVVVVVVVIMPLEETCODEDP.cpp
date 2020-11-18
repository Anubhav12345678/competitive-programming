class Solution {
public:
    int dp[75][75][75];
    int solve(vector<vector<int>> &g,int n,int m,int r,int c1,int c2){
        if(r>=n)  return 0;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nc1 = c1+i;
                int nc2 = c2+j;
                if(nc1>=0&&nc1<m&&nc2>=0&&nc2<m){
                    ans = max(ans,solve(g,n,m,r+1,nc1,nc2));
                }
            }
        }
        int x = ((c1==c2)?(g[r][c1]):(g[r][c1]+g[r][c2]));
        return dp[r][c1][c2]=(ans+x);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid,n,m,0,0,m-1);
    }
};
/*
Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can
 collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located 
at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.

*.