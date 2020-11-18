#include <bits/stdc++.h>
using namespace std;
#define ll long  long
/*
choose any 2 no in [l,r] having max or val l<=r<=10^18
*/
ll solve(ll l,ll r)
{
	ll lxr  =l^r;
	ll msbpos=0;
	while(lxr)
	{
		msbpos++;
		lxr>>=1;
	}
	ll ans=0,two=1;
	while(msbpos--)
	{
	  	ans+=two;
	  	two<<=1;
	}
	return ans;
}
int main() {
	ll t,l,r;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		ll x = solve(l,r);
		x=x|r;
		cout<<x<<endl;
	}
	// your code goes here
	return 0;
}