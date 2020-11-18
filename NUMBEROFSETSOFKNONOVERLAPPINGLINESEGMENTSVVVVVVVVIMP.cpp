static int mod=1e9+7;
class Solution {
public:
    int dp[1001][1001];
    int fun(int n,int k)
    {
        if(k==1) 
        {
            return dp[n][k]=(n*(n-1))/2;
        }
        if(n==1) return 0;
        if(n-1==k) return 1;
        if(n-1<k) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        int tot=0;
        tot=(tot+fun(n-1,k))%mod;// ignoring this point as starting point 
        // now including this point
        for(int i=1;i<n;i++)
        {
            tot = (tot+fun(n-i,k-1))%mod;
        }
        return dp[n][k]=tot%mod;
        
    }
    int numberOfSets(int n, int k) {
      for(int i=0;i<1001;i++)
      {
          for(int j=0;j<1001;j++) dp[i][j]=-1;
      }
        return fun(n,k);
        
    }
};
/*
Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.

Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

 

Example 1:


Input: n = 4, k = 2
Output: 5
Explanation: 
The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.


*/