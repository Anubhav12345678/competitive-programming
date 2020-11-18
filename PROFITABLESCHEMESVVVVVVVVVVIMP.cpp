class Solution {
public:
    // dp[i][j] schhemes with profit i and members j
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(P+1,vector<int>(G+1,0));
        int i,j,k,l,n,m;
        dp[0][0]=1;
        int mod = 1e9+7;
        for(k=0;k<group.size();k++)
        {
            int p = profit[k];
            int g = group[k];
            for(i=P;i>=0;i--)
            {
              for(j=G-g;j>=0;j--)
              {
                  dp[min(i+p,P)][j+g] = (dp[min(i+p,P)][j+g]+dp[i][j])%mod;
              }
            }
        }
        int x=0;
        for(auto v:dp[P]) x = (x+v)%mod;
        return x;
    }
};
/*
There is a group of G members, and a list of various crimes they could commit.

The ith crime generates a profit[i] and requires group[i] members to participate in it.

If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least P profit, and the total number 
of members participating in that subset of crimes is at most G.

How many schemes can be chosen?  Since the answer may be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: G = 5, P = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: 
To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.


*/