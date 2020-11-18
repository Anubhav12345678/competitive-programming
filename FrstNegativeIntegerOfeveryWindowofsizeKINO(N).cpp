#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<deque>
//in O(N)
int main() {
	ll n,a[1000001],i,j,k;
	cin>>n>>k;
	for(i=0;i<n;i++)
	cin>>a[i];
	deque<ll> q;
	for(i=0;i<k;i++)
	if(a[i]<k)
	q.push_back(i);
	for(;i<n;i++)
	{
		if(!q.empty())
		cout<<a[q.front()]<<" ";
		else
		cout<<0<<" ";
		while(!q.empty()&&q.front()<(i-k+1))
		q.pop_front();
		if(a[i]<0)
		q.push_back(i);
	}
	if(!q.empty())
	cout<<a[q.front()]<<" ";
	else
	cout<<"0"<<" ";
	// your code goes here
	return 0;
}