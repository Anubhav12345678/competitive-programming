class Solution {
public:
    /*

Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.


    */
    //meeeeeeeeeeeeeeeee
    class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int i,j,k,l,n=s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // if s2 is empty
        // dp[i][j] = cost of s1.substr(0,i) and s2.substr(0,j);
        dp[0][0]=0;
        for(i=1;i<=n;i++)
            dp[i][0] = dp[i-1][0]+ s1[i-1];
        for(i=1;i<=m;i++)
            dp[0][i] =  dp[0][i-1]+ s2[i-1];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[n][m];
    }
};






















    int minimumDeleteSum(string s1, string s2) {
        int i,j,k,l,n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         Let dp[i][j] be the answer to the problem for the strings s1[i:], s2[j:].
        
        for(i=n-1;i>=0;i--)
            dp[i][m] = dp[i+1][m]+(int)(s1[i]);
        for(i=m-1;i>=0;i--)
            dp[n][i] = dp[n][i+1] + (int)(s2[i]);
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                    dp[i][j] = dp[i+1][j+1];
                else{
                    dp[i][j] = min(dp[i+1][j]+(int)(s1[i]),dp[i][j+1]+(int)(s2[j]));
                }
            }
        }
        return dp[0][0];
    }
};