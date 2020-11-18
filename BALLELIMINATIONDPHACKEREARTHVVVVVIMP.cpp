#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
int main(){

/*
You have a sequence of balls. Every ball has a color. You can eliminate any single ball and pay one pound. Also you can eliminate any two neighboring balls which have the same colors for no cost.
Find minimal amount you need to spend to eliminate all balls.
*/
   ll i,j,k,l,n,m;
   cin>>n;
   ll a[n];
   for(i=0;i<n;i++) cin>>a[i];
   ll dp[n+1][n+1];
   memset(dp,0LL,sizeof(dp));
   for(l=1;l<=n;l++){
       for(i=0;i+l<=n;i++){
           j=i+l;
           ll &cur = dp[i][j];
           cur = dp[i+1][j]+1;
           for(k=i+1;k<j;k++){
               if(a[i]==a[k])
               cur = min(cur,dp[i+1][k]+dp[k+1][j]);
           }
       }
   }
   
   cout<<dp[0][n]<<" ";
  //dp[i][j] min cost from i to j-1


















    return 0;
}






















