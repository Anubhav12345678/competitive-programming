#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll skipone(ll a[],ll n)
{
	ll incl=a[0];
	ll exc = 0;
	ll res;
	for(ll i=1;i<n;i++)
	{
		res = a[i] + min(incl,exc);
		exc = incl;
		incl = res;
	}
	return min(exc,incl);
}
int main() {
	ll t,n,a[101],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<skipone(a,n)<<endl;
		
	}
	// your code goes here
	return 0;
}