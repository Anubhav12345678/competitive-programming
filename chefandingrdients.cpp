#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll invmod(ll n)
{
	ll p = mod-2;
	ll ans = 1;
	while(p>0)
	{
		if(p%2==1)
		{
			ans*=n;
			ans= ans%mod;
		}
		n*=n;
		n = n%mod;
		p/=2;
	}
	return ans;
}
int main() {
	ll n,k,t,a,d,N,l;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		a = k-1;
		d = n-1;
		N = ((a)/d)+1;
		d*=-1;
		l = a+(N-1)*d;
		// cout<<a<<" "<<d<<" "<<N<<" "<<l<<" "<<invmod(2)<<endl;
		cout<<(((N%mod)*((((a%mod+l%mod)%mod)*invmod(2))%mod))%mod)%mod<<endl;
	}
	// your code goes here
	return 0;
}