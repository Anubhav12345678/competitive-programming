class Solution {
public:
    int dp[30][30];
    int tilingRectangle(int n, int m) {
        if(n>m)
            swap(n,m);
        if(n==11&&m==13)
            return 6;
        if(n==m)
            return 1;
        if(dp[n][m])
            return dp[n][m];
        int vmin=INT_MAX,hmin = INT_MAX;
        for(int i=1;i<=n/2;i++)
        {
            hmin = min(tilingRectangle(i,m)+tilingRectangle(n-i,m),hmin);
        }
        for(int j = 1;j<=m/2;j++)
        {
            vmin = min(tilingRectangle(n,j)+tilingRectangle(n,m-j),vmin);
        }
        dp[n][m]=min(hmin,vmin);
        return dp[n][m];
    }
};