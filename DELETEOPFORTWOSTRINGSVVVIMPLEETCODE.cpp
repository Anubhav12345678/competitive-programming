class Solution {
public:
    int lcs(string a,string b)
    {
        int i,j,k,l,n=a.size(),m=b.size();
        int dp[n+1][m+1];
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        cout<<lcs(word1,word2)<<endl;
        return word1.size()+word2.size()-2*lcs(word1,word2);
    }
};