class Solution {
public:
    /*
There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.

A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.

Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.

 

Example 1:

Input: stones = [3,2,4,1], K = 2
Output: 20
Explanation: 
We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.


//O(n^3) time
        //O(n^2*K) space

    */
    int mergeStones(vector<int>& stones, int K) {
        //O(n^3) time
        //O(n^2*K) space
        int i,j,k,l,m,n=stones.size();
        if((n-1)%(K-1)) return -1;
        int inf = 1e9;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(K+1,inf)));
        for(i=0;i<n;i++)
            dp[i][i][1] = 0;
        vector<int> sum(n+1,0);
        for(i=1;i<=n;i++)
          sum[i] = sum[i-1]+stones[i-1];
            for(l=2;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                for(k=2;k<=K;k++)
                {
                    for(m=i;m<j;m++)
                        dp[i][j][k] = min(dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1]);
                    dp[i][j][1] = dp[i][j][k]+sum[j+1]-sum[i];
                }
            }
        }
        return dp[0][n-1][1];
    }
};