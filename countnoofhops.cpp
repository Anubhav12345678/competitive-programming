#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n)
{
	if(n<=0)
	return 0;
	// if(n==1)
	// return 1;
	ll dp[n+1]= {0};
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(ll i=4;i<=n;i++)
	dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	return dp[n];
	// if(n==2)
	// return 2;
	// if(n==3)
	// return 3;
	// return 1+solve(n-1)+solve(n-2)+solve(n-3);
}
int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
	// your code goes here
	return 0;
}