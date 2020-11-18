#include <bits/stdc++.h>
using namespace std;
#define ll long long
void merge(ll a[],ll l,ll m,ll r)
{
	ll n1 = m-l+1;
	ll n2 = r-m;
	ll L[n1],R[n2],i,j,k;
	i=j=k=0;
	ll newe[n1+n2];
	for(i=0;i<n1;i++)
	L[i] = a[l + i];
	for(i=0;i<n2;i++)
	R[i] = a[m+1+i];
	i=0;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			newe[k] = L[i];
			i++;
		}
		else
		{
			newe[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	newe[k++] = L[i++];
	while(j<n2)
	newe[k++] = R[j++];
	for(i=l;i<=r;i++)
	a[i] = newe[i-l];
}
void mergesort(ll a[],ll l,ll r)
{
	if(l<r)
	{
		ll mid = l+(r-l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main() {
	ll a[100001],i,j,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		mergesort(a,0,n-1);
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<"\n";
	}
	// your code goes here
	return 0;
}