#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
#include<string.h>
ll dp[47][47];
ll solve(string s,ll i,ll j)
{
	if(j<i)
	return 0;
	if(i==j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	if(s[i]==s[j])
	dp[i][j] = solve(s,i+1,j-1);
	else
	dp[i][j] = 1+min(solve(s,i+1,j),solve(s,i,j-1));
	return dp[i][j];
    // ll n = s.size();
    // if(n==1)
    // return 0;
    // ll dp[n][n];
    // ll i,j,k;
    //   memset(dp,INT_MAX,sizeof(dp));
    // for(i=0;i<n;i++)
    // dp[i][i]=0;
    // for(i=0;i<n;i++)
    // for(j=0;j<=i;j++)
    // dp[i][j]=0;
    // for(i=0;i<n;i++)
    // {
    //     for(j=i+1;j<n;j++)
    //     {
    //         if(s[i]==s[j])
    //         dp[i][j] = dp[i+1][j-1];
    //         else
    //         dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
    //     }
    // }
    // return dp[0][n-1];
}
int main() {
	ll t;
	string s;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>s;
		cout<<solve(s,0,s.size()-1)<<endl;
	}
	// your code goes here
	return 0;
}