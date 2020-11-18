int dp[1005][1005];
// void make(vector<vector<int>> &v){
//     int n = v.size()-1;
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++)
//         dp[i][j]=0;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+v[i][j];
//         }
//     }
// }
/*
Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all
 the elements in submatrix is maximum.
*/
int Solution::solve(vector<vector<int> > &A, int B) {
    int i,j,k,l,n=A.size();
    vector<vector<int>> v(n,vector<int>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          v[i][j]=A[i][j];
        //   dp[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<n;j++)
        v[j][i]+=v[j-1][i];
    }
    
    int ans=INT_MIN;
    for(i=0;i<n;i++){
        for(j=0;j<B;j++) A[j][i] = v[j][i];
        for(j=B;j<n;j++) A[j][i] = v[j][i]-v[j-B][i];
    }
    
    for(i=B-1;i<n;i++){
        for(j=0;j<n-B+1;j++){
            int sum=0;
            for(k=j;k<j+B;k++)
            sum+=A[i][k];
            ans = max(ans,sum);
        }
    }
    
    return ans;
    
    
    
    
}
