class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int i,j,k,l;
        int maxlen=1,curlen=1,a,b,c=0;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            dp[i][i]=1;
        for(l=2;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                if(s[i]==s[j])
                    dp[i][j]=2+dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};