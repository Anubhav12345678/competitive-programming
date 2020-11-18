/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.


*/


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m  =matrix[0].size();
        int i,j,k,l,ans=0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                dp[i][j]=matrix[i][j];
                //dp[i][j]=edge of largest square with right bottom corner at (i, j);
                if(i&&j&&dp[i][j])
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};