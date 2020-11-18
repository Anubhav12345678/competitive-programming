#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
ll max(ll a,ll b){ return (a>b)?a:b;}
ll solve(ll a[],ll n,ll k)
{
	int i,j,l,m,maxele=INT_MIN;
	for(i=0;i<n;i++)
	maxele = max(maxele,a[i]);
	int p = (1<<(int)(log2(maxele)+1))-1;
	int dp[n+1][p+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=p;j++)
		{
			dp[i][j] = dp[i-1][j]+dp[i-1][j^a[i-1]];
		}
	}
	return dp[n][k];
}
int main() {
    ll arr[] = {1, 2, 3, 4, 5}; 
    ll k = 4; 
    ll n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Count of subsets is " << solve(arr, n, k); 
    return 0; 
}