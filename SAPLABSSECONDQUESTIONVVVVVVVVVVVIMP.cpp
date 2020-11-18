#include <bits/stdc++.h>
using namespace std;
#define ll long long
static ll mod  =1e9+7;
#include<vector>
ll dp[2500][2500];
ll solve(ll curlen,ll len,ll curk)
{
	if(dp[curlen][curk]!=-1)
	return dp[curlen][curk]%mod;
	if(curlen==len)
	{
		return dp[curlen][curk]=(21*1LL)+(curk?5:0);
	}
	if(curk==0)
	dp[curlen][curk]=21*(1LL)*solve(curlen+1,len,curk);
	else
	dp[curlen][curk] = 21*(1LL)*solve(curlen+1,len,curk)+5*(1LL)*solve(curlen+1,len,curk-1);
	return dp[curlen][curk]%mod;
}
int main() {
	memset(dp,-1,sizeof(dp));
	ll n,k;
	cin>>n>>k;
	cout<<solve(1,n,k)%mod;
	// your code goes here
	return 0;
}