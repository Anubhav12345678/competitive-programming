#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
	if(n==1)
	return 1;
	ll i,j,k,lis[100001],lds[100001];
	for(i=0;i<n;i++)
	{
		lis[i] = 1;
		lds[i] = 1;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		if(a[i]>a[j]&&lis[i]<lis[j]+1)
		lis[i] = lis[j]+1;
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=i+1;j<n;j++)
		if(a[i]>a[j]&&lds[i]<lds[j]+1)
		lds[i] = lds[j]+1;
	}
	ll mini=-1;
	for(i=0;i<n;i++)
	mini = max((lis[i]+lds[i]-1),mini);
	return mini;
}
int main() {
	ll a[100001],n,t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<solve(a,n)<<endl;
	}
	// your code goes here
	return 0;
}