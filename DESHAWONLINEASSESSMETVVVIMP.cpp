#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n,ll k)
{
	ll pow2=1;
	ll dp[n+1];
	ll runsum=0LL;
	ll mod  =1e9+7;
	for(ll i=n;i>=(n-k);i--)
	{
		dp[i] = pow2;
		runsum = (runsum+dp[i])%mod;
		pow2*=2;
	}
	for(ll i=n-k-1;i>=0;i--)
	{
		dp[i] = runsum;
		runsum-=dp[i+k+1];
		runsum+=dp[i];
	}
	return dp[0];
}
int main() {
	ll i,j,k,l,n,m;
	cin>>n>>k;
	cout<<solve(n,k)<<endl;
	// your code goes here
	return 0;
}
/*
Find the number of plays in which you lose consecutively less than or equal to k times.
The number of games is n.
Constraints: 0<=k<=n<=1e5
Example 1: n=3 , k=2
Output: 7
Explanation: (W here means win and L means lose)
WWW
WWL
WLW
LWW
LLW
WLL
LWL


*/