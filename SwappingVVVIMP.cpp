#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t,a[100001],i,j,k,l,n;
	cin>>t;
	while(t--)
	{
		// ll dp[100005];
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>a[i];
		ll dp[n+1];
		dp[0]=0;
		dp[1]=a[1];
		for(i=2;i<=n;i++)
		{
			dp[i] = max(dp[i-1]+a[i]*i,dp[i-2]+a[i]*(i-1)+a[i-1]*i);
		}
		cout<<dp[n]<<endl;
	}
	// your code goes here
	return 0;
}