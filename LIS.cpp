#include <bits/stdc++.h>
using namespace std;
#define ll long long
// cal LIS in  O(n^2)
ll LIS(ll a[],ll n)
{
	if(n==1)
	return 1;
	ll lis[n],i,j;
	for(i=0;i<n;i++)
	lis[i]=1;
	ll maxi=lis[0];
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i]&&lis[i]<(lis[j]+1))
			lis[i] = lis[j]+1;
		}
		maxi = max(maxi,lis[i]);
	}
	return maxi;
}
int main() {
	ll n;
	cin>>n;
	ll a[100001],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<LIS(a,n)<<endl;
	// your code goes here
	return 0;
}