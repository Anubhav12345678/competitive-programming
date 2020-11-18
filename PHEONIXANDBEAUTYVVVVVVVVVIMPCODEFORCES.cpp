#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<set>
/*

Phoenix loves beautiful arrays. An array is beautiful if all its subarrays of length k have the same sum. A subarray of an
 array is any sequence of consecutive elements.

Phoenix currently has an array a of length n. He wants to insert some number of integers, possibly zero, into
 his array such that it becomes beautiful. The inserted integers must be between 1 and n inclusive. Integers may be inserted 
anywhere (even before the first or after the last element), and he is not trying to minimize the number of inserted integers.



*/
void solve()
{
	ll n,k,i,j,l,t;
	cin>>n>>k;
	set<ll> st;
	vector<ll> v;
	for(i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		v.push_back(x);
		st.insert(x);
	}
	if(st.size()>k)
	{
		cout<<-1<<endl;
		return;
	}
	cout<<n*k<<endl;
	for(i=0;i<n;i++)
	{
		for(auto it:st)
		cout<<it<<" ";
		for(j=0;j<k-st.size();j++)
		cout<<1<<" ";
	}
	cout<<endl;
	
	
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	// your code goes here
	return 0;
}