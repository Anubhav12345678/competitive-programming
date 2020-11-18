#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
The new ITone 6 has been released recently and George got really keen to buy it. 
Unfortunately, he didn't have enough money, so George was going to work as a
 programmer. Now he faced the following problem at the work.

Given a sequence of n integers p 1, p 2, ..., p n. You are to choose k pairs of integers:

[l 1, r 1], [l 2, r 2], ..., [l k, r k] (1 ≤ l 1 ≤ r 1 < l 2 ≤ r 2 < ... < l k ≤ r k ≤ n; r i - l i + 1 = m), 
in such a way that the value of sum  is maximal possible. Help George to cope with the task.




*/
ll solve(vector<ll> &v,ll m,ll K)
{
	ll i,j,k,l,n=v.size();
	// m lengtyh ke K subarrays
	vector<vector<ll>> dp(K+1,vector<ll>(n+1,0));
	for(i=0;i<=n;i++)
	dp[0][i]=0;
	for(i=1;i<=K;i++)
	dp[i][0]=0;
	vector<ll> pre(n+1,0);
	// pre[0]= v[0];
	for(i=1;i<=n;i++)
	pre[i] = pre[i-1]+v[i-1];
	for(i=1;i<=K;i++)
	{
		for(j=1;j<=n;j++)
		{
			if((i*m)>j) dp[i][j]=0LL;
			else
			{
				// dp[i][j-1] = ignore jth index and take sum choosing ith subsequence last index as j-1 
				// 2nd term choose i-1 sequences till j-m then add subarray sum from v[j-m+1] to v[j];
				// cout<<"entered";
				dp[i][j] = max(dp[i][j-1], dp[i-1][j-m]+pre[j]-pre[j-m]);
			}
		}
	}
	return dp[K][n];
}
int main() {
	
	ll i,j,k,l,n,m,K;
	cin>>n>>m>>k;
	vector<ll> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	cout<<solve(v,m,k)<<endl;
	// your code goes here
	return 0;
}