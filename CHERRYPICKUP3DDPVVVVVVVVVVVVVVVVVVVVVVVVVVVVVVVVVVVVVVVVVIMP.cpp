class Solution {
public:
    int dp[51][51][51];
    vector<vector<int>> g;
    int helper(int r1,int c1,int c2,int n){
        int r2= r1+c1-c2;
        if(r1<0||r2<0||c1<0||c2<0||r1>=n||r2>=n||c1>=n||c2>=n||g[r1][c1]==-1||g[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)  return dp[r1][c1][c2];
        if(r1==n-1&&c1==n-1) return g[r1][c1];
        int ans=0;
        ans+=g[r1][c1];
        if(r1!=r2) ans+=g[r2][c2];
        int tmp = ans;
        tmp= max(helper(r1,c1+1,c2+1,n),helper(r1,c1+1,c2,n));
        tmp  =max(tmp,helper(r1+1,c1,c2+1,n));
        tmp  =max(tmp,helper(r1+1,c1,c2,n));
        ans+=tmp;
        return dp[r1][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        g=grid;
        memset(dp,-1,sizeof(dp));
        int n=g.size();
        return max(0,helper(0,0,0,n));
    }
};
/*
instaed of going twice through the grid we take 2 perdsons to go from 0,0 to n-1,n-1 as going 
from 0,0, to n-1,n-1 is similar to going from n-1,n-1 to 0,0 

In a N x N grid representing a field of cherries, each cell is one of three possible integers.

 

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.
 

Your task is to collect maximum number of cherries possible by following the rules below:

 

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
 

 

Example 1:

Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

*/