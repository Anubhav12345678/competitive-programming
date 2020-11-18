#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*

We saw the little game Marmot made for Mole's lunch. Now it's Marmot's dinner time 
and, as we all know, Marmot eats flowers. At every dinner he eats some red and white flowers.
 Therefore a dinner can be represented as a sequence of several flowers, some of them white and some of them red.

But, for a dinner to be tasty, there is a rule: Marmot wants to eat white flowers only in groups of size k.

Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could
 be very large, print it modulo 1000000007 (109 + 7).



*/
// #define mod 1e9+7
ll mod = 1e9+7;
vector<ll> pre;
vector<ll> dp;
ll solve(ll n,ll k)
{
	if(n==0) return 1;
	if(dp[n]!=-1) return dp[n];
	ll ans = 0LL;
	if(n>=k)
	{
	 ans = (ans+solve(n-k,k));
	 ans = ans%mod;
	}
	ans = (ans+solve(n-1,k)); ans = ans%mod;
	
	return dp[n] = ans%mod;
}

void init(ll k){
	pre = vector<ll>(100005,0);
	dp = vector<ll>(100005,-1);
	for(ll i=1;i<100005;i++)
	{
		pre[i] = (pre[i-1] + solve(i,k))%mod; 
	}
}
int main() {
	
	pre = vector<ll>(100005,0);
	dp = vector<ll>(100005,-1);
	// init();
	ll t,k,a,b;
	cin>>t>>k;
	init(k);
	// cin>>t>>k;
	while(t--)
	{
		cin>>a>>b;
		cout<<((pre[b]-pre[a-1])+mod)%mod<<endl;
	}
	
	// your code goes here
	return 0;
}