#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2)));
        for(i=0;i<n;i++)
        {
            dp[i][i][0]=nums[i];
            dp[i][i][1] = nums[i];
        }
        for(int sz= 2;sz<=n;sz++)
        {
            for(i=0;i<=n-sz;i++)
            {
                j=i+sz-1;
                dp[i][j][0]=INT_MAX;
                dp[i][j][1] = INT_MIN;
                
                for(k=i;k<j;k++)
                {
                    // combine with addition
                    dp[i][j][0] = min(dp[i][j][0],dp[i][k][0]+dp[k+1][j][0]);
                    dp[i][j][1]  = max(dp[i][j][1],dp[i][k][1]+dp[k+1][j][1]);
                    // combine with subtraction
                    dp[i][j][0] = min(dp[i][j][0],dp[i][k][0]-dp[k+1][j][1]);
                    dp[i][j][1] = max(dp[i][j][1],dp[i][k][1]-dp[k+1][j][0]);
                    // combine with multiplication
                    dp[i][j][0] = min(dp[i][j][0],min(dp[i][k][0]*dp[k+1][j][1],dp[i][k][1]*dp[k+1][j][0]));
                    dp[i][j][1] = max(dp[i][j][1],max(dp[i][k][0]*dp[k+1][j][0],dp[i][k][1]*dp[k+1][j][1]));
                }
            }
        }
        
        return dp[0][n-1][1];
    }
};
/*
Given a list of integers nums, return the maximal value that can be made by adding any binary operators +, -, and * 
between the numbers in nums as well as insert any valid brackets.

Example 1
Input

nums = [-5, -3, -8]



*/