#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
ll dp[100001];
ll solve(ll n,ll a,ll b,ll c)
{
	if(n==0)
	return 0;
	if(n<0)
	return INT_MIN;
	if(dp[n]!=-1)
	return dp[n];
	return dp[n] = 1+max(solve(n-a,a,b,c),max(solve(n-b,a,b,c),solve(n-c,a,b,c)));
	
}
int main() {
	memset(dp,-1,sizeof(dp));
	ll n,a,b,c;
	cin>>n>>a>>b>>c;
	cout<<solve(n,a,b,c);
	// your code goes here
	return 0;
}