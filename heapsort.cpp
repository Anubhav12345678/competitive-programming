//heap sort
#include <bits/stdc++.h>   
using namespace std;
#define ll long long

void maxheapify(ll a[],ll n,ll i)
{
	ll largest =i;
	ll l =2*i+1;
	ll r = 2*i+2;//assuming 0 based indexing
	if(l<n&& a[l]>a[largest])
		largest=l;
	if(r<n&& a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		ll t = a[i];
		a[i] = a[largest];
		a[largest] = t; 
		maxheapify(a,n,largest);
	}
}

void heapsort(ll a[],ll n)
{
	ll i;
	//build a max heap for details view https://www.youtube.com/watch?v=WsNQuCa_-PU&t=301s
	for(i=n/2-1;i>=0;i--)
	{
		maxheapify(a,n,i);
	}
	//one by one extract elements from the heap
	for(i=n-1;i>=0;i--)// ulta array aise as we need to replace the last ele in the tree with the root
	{
		ll t = a[i];
		a[i] = a[0];
		a[0] = t; 
		maxheapify(a,i,0);//// call max heapify on the reduced heap 
	}
}
int main()
{
	ll t,n,a[100005],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		heapsort(a,n);
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}