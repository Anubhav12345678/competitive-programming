 int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        int i,j,k,l;
        int dp[m+1][n+1];
        // memset(dp,INT_MAX,sizeof(dp));
        dp[0][0] = grid[0][0];
        for(i=1;i<m;i++)
            dp[i][0] = dp[i-1][0]+grid[i][0];
        for(i=1;i<n;i++)
            dp[0][i] = dp[0][i-1]+grid[0][i];
        // for(i=1;i<m;i++)
        //     dp[i][0] = dp[i-1][0]+grid[i][0];
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }

    //me
    class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i,j,k,l;
        int dp[n][m];
        dp[0][0] = grid[0][0];
        for(i=1;i<m;i++)
            dp[0][i] = dp[0][i-1]+grid[0][i];
        for(i=1;i<n;i++)
            dp[i][0] = dp[i-1][0]+grid[i][0];
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
        }
        return dp[n-1][m-1];
        
    }
};