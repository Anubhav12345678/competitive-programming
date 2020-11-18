#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n,ll sum)
{
	ll i,j,k;
	ll dp[sum+1][n+1];
    memset(dp,0,sizeof(dp));
    for(i=0;i<=n;i++)
    dp[0][i]=1;
    for(i=1;i<=sum;i++)
    dp[i][0]=0;
    for(i=1;i<=sum;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		dp[i][j] = dp[i][j-1];
    		if(i>=a[j-1])
    		dp[i][j]+=dp[i-a[j-1]][j-1];
    	}
    }
    return dp[sum][n];
}
int main() {
	ll t,a[100005],i,j,k,n,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		cin>>sum;
		cout<<solve(a,n,sum)<<endl;
	}
	// your code goes here
	return 0;
}