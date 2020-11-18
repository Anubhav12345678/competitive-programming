class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int i,j,k,l,n=A.size();
        vector<vector<int>> dp(501,vector<int>(n,0));
        for(i=0;i<=500;i++)
        {
            if(i==A[0])
                dp[i][0]++;
            for(j=1;j<n;j++)
            {
                if(A[j]==i)
                    dp[i][j] = dp[i][j-1]+1;
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        int ans=0;
        int mod =1e9+7;
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                int x = target-A[i]-A[j];
                if(x>=0)
                    ans=(ans+(dp[x][n-1]-dp[x][j]))%mod;
            }
        }
        return ans;
    }
};