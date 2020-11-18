#include <bits/stdc++.h>
using namespace std;
#define ll long long
// max sum increasing subsequence
ll solve(ll a[],ll n)
{
	ll i,j,s=0;
	ll lis[n];
	for(i=0;i<n;i++)
	lis[i] = a[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j]&&(lis[i]<(lis[j]+a[i])))
			lis[i] = lis[j]+a[i];
		}
	}
	ll maxi = -1;
	for(i=0;i<n;i++)
	maxi = max(maxi,lis[i]);
	return maxi;
}
int main() {
	ll n,a[10001];
	cin>>n;
	for(ll i=0;i<n;i++)
	cin>>a[i];
	cout<<solve(a,n)<<endl;
	// your code goes here
	return 0;
}