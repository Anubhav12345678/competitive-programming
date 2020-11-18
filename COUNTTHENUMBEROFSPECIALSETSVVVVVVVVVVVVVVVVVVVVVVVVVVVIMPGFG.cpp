#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

An ordered set of integers is said to be a special set if for every element of the
 set X, the set does not contain the element X + 1. Given an integer N, the task is 
 to find the number of special sets whose largest element is not greater than N. Since,
  the number of special sets can be very large, print the answer modulo 109 + 7.


*/
ll mod = 1e9+7;
#include<vector>
ll sum(ll a,ll b)
{
	return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b)
{
	return ((a%mod)*(b%mod))%mod;
}
ll solve(ll n)
{
	// dp[i][j] is the no of subsets of len i ending with j
	ll dp[2001][2001];
	memset(dp,0,sizeof(dp));
	ll i,j,k,l,x,y,z,cnt=0,ways=1,ans=0;
	for(i=1;i<=n;i++)
	{
		dp[1][i] = 1;
		dp[1][i]+= dp[1][i-1];
	}
	for(i=2;i<=n;i++)
	{
		
		// jth num ko include  kro
		for(j=2;j<=n;j++)
		dp[i][j] = dp[i-1][j-2];
		// jth num ko include na kro
		for(j=1;j<=n;j++)
		dp[i][j] = sum(dp[i][j],dp[i][j-1]);
	}
	for(i=1;i<=n;i++)
	{
		ways = mul(ways,i);
		ans = sum(ans,mul(ways,dp[i][n]));
	}
	return ans;
}
int main() {
	ll n = 4;
	cout<<solve(n)<<endl;
	// your code goes here
	return 0;
}