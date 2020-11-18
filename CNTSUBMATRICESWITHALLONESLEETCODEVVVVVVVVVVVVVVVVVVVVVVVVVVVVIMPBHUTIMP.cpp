class Solution {
public:
    //Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i,j,k,l;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            int c=0;
            for(j=m-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                    c=0;
                else
                    c++;
                dp[i][j]=c;
            }
        }
        // for(i=0;i<n;i++)
        // {
        //     for(j=0;j<m;j++)
        //         cout<<"dp["<<i<<"]["<<j<<"]=  "<<dp[i][j]<<endl;
        // }
        int ans=0;
        for(j=0;j<m;j++)
        {
            for(i=0;i<n;i++)
            {
                int x = INT_MAX;
                    for(k=i;k>=0;k--)
                    {
                        x = min(x,dp[k][j]);
                        ans+=x;
                    }
            }
        }
        return ans;
    }
};