#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
// ll dp[10004][10004];
ll solve(ll n)
{
 if(n==1)
 return 1;
 if(n%2==0)
 return 1+solve(n/2);
 else
 return 1+solve(n-1);
}
int main() {
      //memset(dp,-1,sizeof(dp));
      
	ll t,n;
	cin>>t;
	while(t--)
	{
	   // for(ll i = 0;i<10004;i++)
	   // dp[i]=-1;
	   //memset(dp,-1,sizeof(dp));
		cin>>n;
		cout<<solve(n)<<endl;
	}
	// your code goes here
	return 0;
} 