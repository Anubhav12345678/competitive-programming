/*
Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

A kingdom area is defined as a N x M grid with each cell denoting a village.
Each cell has a value which denotes the strength of each corresponding village.
The strength can also be negative, representing those warriors of your kingdom who were held hostages.

There’s also another thing to be noticed.

The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
(stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.







//another


*/

// another

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m = A[0].size();
   int dp[n+2][m+2]={0};
dp[n-1][m-1]=A[A.size()-1][A[0].size()-1];

int maxi=INT_MIN;
maxi=max(dp[n-1][m-1],maxi);

if(n==1 &&m==1) return A[0][0];
for(int i=n-2;i>=0;i--){
    
    dp[i][m-1]=dp[i+1][m-1]+A[i][m-1];
    maxi=max(maxi,dp[i][m-1]);
    
}
for(int i=m-2;i>=0;i--){
    
    dp[n-1][i]=dp[n-1][i+1]+A[n-1][i];
    maxi=max(maxi,dp[n-1][i]);
}
for(int i=n-2;i>=0;i--){
     for(int j=m-2;j>=0;j--){
        dp[i][j]=dp[i][j+1]+A[i][j]+dp[i+1][j]-dp[i+1][j+1];    

         maxi=max(maxi,dp[i][j]);
       
     }   

}

return maxi;
}





int Solution::solve(vector<vector<int> > &A) {
    int ans,i,j,dn,rig,r,c,sum;
    int n=A.size();
    int m=A[0].size();
    vector<vector<int> > rsum=A;
    for(r=0;r<n;r++)
    {
        for(c=m-2;c>=0;c--)
        {
            rsum[r][c]=A[r][c]+rsum[r][c+1];
        }
    }
    int ma=A[n-1][m-1];
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for(j=m-1;j>=0;j--)
    {
        for(i=n-1;i>=0;i--)
        {
            rig=0;
            dn=0;
            if(i!=n-1)
            {
                dn=dp[i+1][j];
            }
            if(j!=m-1)
            {
                rig=rsum[i][j+1];
            }
            dp[i][j]=A[i][j]+rig+dn;
            ma=max(ma,dp[i][j]);
        }
    }
    return(ma);
}
