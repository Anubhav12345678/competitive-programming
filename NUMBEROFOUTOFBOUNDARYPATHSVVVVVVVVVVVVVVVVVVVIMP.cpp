class Solution {
public:
/*

There is an m by n grid with a ball. Given the start
 coordinate (i,j) of the ball, you can move the ball to adjacent 
 cell or cross the grid boundary in four directions (up, down, left, right).
  However, you can at most move N times. Find out the number of paths to move the ball 
  out of grid boundary. The answer may be very large, return it after mod 109 + 7.
Example 1:

Input: m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
*/
    int mod = 1e9+7;
    long long int dp[55][55][55];
    long long int solve(int r,int c,int N,int i,int j)
    {
        if(i<0||j<0||i==r||j==c) return 1LL;
        if(N==0) return 0LL;
        if(dp[N][i][j]!=-1)
            return dp[N][i][j]%mod;
        int ans = (solve(r,c,N-1,i+1,j)%mod+solve(r,c,N-1,i-1,j)%mod+solve(r,c,N-1,i,j+1)%mod+solve(r,c,N-1,i,j-1)%mod)%mod;
        return dp[N][i][j] = ans%mod;
    }
    // vector<vector<vector<int>>> dp;
    int findPaths(int m, int n, int N, int i, int j) {
        // dp.resize(N+1);
        // for(i=0;i<=N;i++)
        //     dp[i] = vector<int>(m+1,vector<int>(n+1,-1));
        int a,b,c,k,l;
        for(a=0;a<55;a++)
            for(b=0;b<55;b++)
                for(c=0;c<55;c++)
                    dp[a][b][c]=-1;
        // memset(dp,-1,sizeof(dp));
        return solve(m,n,N,i,j)%mod;
    }
};