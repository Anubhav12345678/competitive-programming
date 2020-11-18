#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<vector<int>>& mat) {
        int i,j,k,l,n=mat.size();
        if(n==0)  return 0;
        int m = mat[0].size();
        if(m==0) return 0;
        int ans=1;
        vector<vector<int>> dp(n,vector<int>(m,1));
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(mat[i][j]==mat[i-1][j]&&(mat[i-1][j]==mat[i][j-1])&&(mat[i][j-1]==mat[i-1][j-1]))
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
        
    }
};
/*
Given a two-dimensional list of integers matrix, find the largest k × k submatrix
 such that all of its elements are the same value, and return the k.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in matrix.
Example 1
Input

matrix = [
    [1, 1, 3],
    [1, 1, 3],
    [5, 5, 5]
]
Output

2


*/