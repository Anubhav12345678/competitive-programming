/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move
 outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].

*/


class Solution {
public:
    int solve(vector<vector<int>> &dp,vector<vector<int>> &v,int i,int j,int pre)
    {
        if(i<0||i>=v.size()||j<0||j>=v[0].size()||v[i][j]<=pre)
            return 0;
        if(dp[i][j]==0)
        {
            dp[i][j] = 1;
            dp[i][j] = max(dp[i][j],1+solve(dp,v,i+1,j,v[i][j]));
            dp[i][j] = max(dp[i][j],1+solve(dp,v,i-1,j,v[i][j]));
            dp[i][j] = max(dp[i][j],1+solve(dp,v,i,j+1,v[i][j]));
            dp[i][j] = max(dp[i][j],1+solve(dp,v,i,j-1,v[i][j])); 
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int i,j,k,l,n=matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        if(m==0)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        // return solve(dp,matrix,n,m,0,0);
        int ans=INT_MIN;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(dp[i][j]==0)
                {
                    dp[i][j] = solve(dp,matrix,i,j,INT_MIN);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};