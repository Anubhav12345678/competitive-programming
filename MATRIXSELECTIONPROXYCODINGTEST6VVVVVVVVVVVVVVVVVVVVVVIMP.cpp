#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<set>
/*

You are given a matrix A of n*m dimensions . You need to select k elements from the matrix such that their sum 
is maximum. The added constraint is that you cannot select an element A[i][j] from the matrix unless all elements before 
it in the same row are
  are selected such that .


*/
int main()
{
    ll i,j,k,l,n,m,p,q,t;
    cin>>n>>m>>k;
    vector<vector<ll>> v(n,vector<ll>(m));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) cin>>v[i][j];
    // for(i=0;i<n;i++)
    //     for(j=0;j<m;j++)
    //         cout<<"v["<<i<<"]["<<j<<"] = "<<v[i][j]<<endl;
    vector<vector<ll> > dp(n,vector<ll>( k+1,0LL));// dp[i][j] =  max sum poss taking j numbers from the first i rows
    for(i=0;i<n;i++)
    {
        for(j=0;j<=k;j++) dp[i][j]=0LL;
    }
    // cout<<v[0][0]<<" "<<v[0][1]<<endl;
    for(i=1;i<=min(m,k);i++)
        dp[0][i] = dp[0][i-1]+ v[0][i-1];
    for(i=1;i<n;i++)
    {
        dp[i][0]=0LL;
        for(j=1;j<=k;j++)
        {
            ll presum=0LL;
            dp[i][j] = dp[i-1][j];
            for(ll x=1;x<=min(j,m);x++)
            {
                presum+=v[i][x-1];
                // cout<<"presum = "<<presum<<endl;
                dp[i][j] = max(dp[i][j], dp[i-1][j-x]+presum);
                
            }
        }
    }
    cout<<dp[n-1][k];
    
    
        
        
        
        
        
        
        
        
    return 0;
}







