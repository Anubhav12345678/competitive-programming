#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<map>
/*
Chef recently read about the mex function and came up with a function similar to that. For a (possibly empty) sequence
 of positive integers S, Chef defines f(S) as the smallest positive integer that does not appear in S.
  For example, f([])=1, f([3,4,3,5])=1, f([2,5,1,1,2,3])=4.

Chef's friend heard about Chef's idea and found it really cool. Therefore, he sent a sequence a1,a2,…,aN to
 Chef and asked him to find the sum of f(S) over all 2N possible subsequences S of this sequence.
  Since Chef is busy, he entrusted you with solving the problem.

Since the resulting sum can be very big, compute it modulo  998,244,353



*/
ll mod = 998244353;
ll power(ll n,ll ind)
{
	if(ind==0)
	return 1;
	ll x = power(n,ind/2)%mod;
	// if(ind%2==0)
	ll y = (x*x)%mod;
	if(ind%2==0)
	return y%mod;
	else
	return (x*x*n)%mod;
}
ll solve(vector<ll> &v)
{
	ll i,j,k,l,n=v.size();
	map<ll,ll> mp;
	for(i=0;i<n;i++) mp[v[i]]++;
	ll add=0LL;
	ll mul=1LL;
	ll ans=0LL;
	for(ll num=1;num<=n+1;num++)
	{
		ll mex = (num*mul)%mod;
		add = (add+mp[num])%mod;
		mex = (mex*power(2,n-add))%mod;
		ans = (ans+mex)%mod;
		mul = (mul*(power(2,mp[num])-1))%mod;
	}
	return ans;
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++) cin>>v[i];
		cout<<solve(v)<<endl;
 	}
	// your code goes here
	return 0;
}