
//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i,j,k,l,n=matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        if(m==0)
            return 0;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            if(dp[i][0]==1)
                ans=1;
        }
        for(i=0;i<m;i++)
        {
            dp[0][i] = matrix[0][i]-'0';
            if(dp[0][i]==1)
                ans=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
                else
                    dp[i][j]=0;
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
        
    }
};