class Solution {
public:
    /*
     You are given a string s containing lowercase letters and an integer k. You need to :

First, change some characters of s to other lowercase English letters.
Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
Return the minimal number of characters that you need to change to divide the string.

 

Example 1:

Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
    */
    int cs(string &s,int i,int j)
    {
        int c=0;
        while(i<j)
        {
            if(s[i++]!=s[j--]) c++;
        }
        return c;
    }
    int palindromePartition(string s, int K) {
        int i,j,k,l,n=s.size();
        int cost[n][n];
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
                cost[i][j] = cs(s,i,j);
        }
        vector<vector<int>> dp(n,vector<int>(K+1,INT_MAX/2));
        //dp[i][k] = min changes to make s[0-i] into k strings
        //dp[i][1] = cost[0][i];
        for(i=0;i<n;i++)
        {
            dp[i][1] = cost[0][i];
            for(k=1;k<=K;k++)
            {
                for(j=0;j<i;j++)
                    dp[i][k] = min(dp[i][k],dp[j][k-1]+cost[j+1][i]);
            }
        }
        return dp[n-1][K];
    }
};