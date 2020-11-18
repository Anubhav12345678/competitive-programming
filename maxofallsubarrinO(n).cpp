#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<deque>
#include<iterator>
// sliding windowmaxofallsubarrays of size k in O(n)
void solve(ll a[],ll n,ll k)
{
	ll i,j,p,m;
	deque<ll> pq;
	deque<ll>::iterator it;
	for(i=0;i<k;i++)//first k elements
	{
		while(!pq.empty()&&a[i]>=a[pq.back()])
		pq.pop_back();
		pq.push_back(i);
	}
	for(;i<n;i++)
	{
		cout<<a[pq.front()]<<" ";
		while(!pq.empty()&&pq.front()<=i-k)
		pq.pop_front();
		while(!pq.empty()&&a[i]>=a[pq.back()])
		pq.pop_back();
		pq.push_back(i);
	}
	cout<<a[pq.front()]<<" ";
}
	
	int main() 
{ 
    ll arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    ll n = sizeof(arr) / sizeof(arr[0]); 
    ll k = 3; 
    solve(arr, n, k); 
    return 0; 
}