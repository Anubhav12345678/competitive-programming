// int lcs(string x,string y)
// {
//     int n=x.size(),m=y.size();
//     int i,j,k,l;
//     int dp[n+1][m+1];
//     memset(dp,0,sizeof(dp));
//     for(i=0;i<=n;i++)
//     {
//         for(j=0;j<=m;j++)
//         {
//             if(i==0||j==0)
//             dp[i][j]=0;
//             else if(x[i-1]==y[j-1])
//             dp[i][j] = dp[i-1][j-1]+1;
//             else
//             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//         }
//     }
//     return dp[n][m];
// }
/*
Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.

*/
int Solution::solve(string A) {
    int i,j,k,l,n=A.size();
    l=0;
    int r = n-1;
    int cnt=0;
    while(l<r){
        if(A[l]==A[r]){
            l++;
            
            r--;
        }
        else{
            if(l==0){
                cnt++;
                r--;
            }
            else{
                cnt+=l;
                l=0;
            }
        }
    }
    return cnt;
}
