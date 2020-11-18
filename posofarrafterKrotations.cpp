#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll a[],ll n,ll k)
{
	ll temp[2*n],i;
	for(i=0;i<n;i++)
	{
		temp[i] = a[i];
		temp[i+n] = a[i];
	}
	for(i=k%n;i<(k%n+n);i++)
	cout<<temp[i]<<" ";
}
int main() {
    ll a[100001],i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    solve(a,n,2);
	// your code goes here
	return 0;
}