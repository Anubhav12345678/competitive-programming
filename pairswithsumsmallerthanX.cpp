#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n,ll x)
{
	ll l=0;
	ll r = n-1;
	ll cnt = 0;
	while(l<r)
	{
		if((a[l]+a[r])<x)
		{
			cnt+=r-l;
			l++;
		}
		else
		r--;
	}
	return cnt;
}
int main() {
	ll n,a[100005],i,j,t,x;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	cin>>x;
	cout<<solve(a,n,x)<<endl;
	
	// your code goes here
	return 0;
}