#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAX 1000005
//using dp count ways to reach nth stair
ll a[MAX];
ll noofways(ll n)
{
	if(a[n]!=-1)
	return a[n]%mod;
	if(n<=1)
	return n;
	ll x = (noofways(n-1))%mod;
	ll y = (noofways(n-2))%mod;
	a[n] = (x+y)%mod;
	return (x+y)%mod;
}
int main() {
	ll t,n,i;
	memset(a,-1,sizeof(a));
	for(i=0;i<MAX;i++)
	{
	a[i] = noofways(i);
	// cout<<a[i+1]<<endl;
	}
	// for(i=0;i<MAX;i++)
	// cout<<a[i+1]<<endl;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n+1]<<endl;
	}
	
	// your code goes here
	return 0;
}