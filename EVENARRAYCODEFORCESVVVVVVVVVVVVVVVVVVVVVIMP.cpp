#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
You are given an array a[0…n−1] of length n which consists of non-negative integers. Note that array indices start from zero.

An array is called good if the parity of each index matches the parity of the element at that index. More formally, an array is good if for all i (0≤i≤n−1) the equality imod2=a[i]mod2 holds, where xmod2 is the remainder of dividing x by 2.

For example, the arrays [0,5,2,1] and [0,17,0,3] are good, and the array [2,4,6,7] is bad, because for i=1, the parities of i and a[i] are different: imod2=1mod2=1, but a[i]mod2=4mod2=0.

In one move, you can take any two elements of the array and swap them (these elements are not necessarily adjacent).

Find the minimum number of moves in which you can make the array a good, or say that this is not possible.



*/
ll solve(vector<ll> &v)
{
	ll i,j,k,l,n=v.size();
	if(n==1) 
	{
		if(v[0]%2==0)
		return 0;
		return -1;
	}
	vector<ll> e,o;
	for(i=0;i<n;i++)
	{
		// cout<<"i = "<<i<<" v["<<i<<"] = "<<v[i]<<endl;
		if(i%2==0&&v[i]%2==1) e.push_back(v[i]);
		if(i%2==1&&v[i]%2==0) o.push_back(v[i]);
	}
	if(o.size()!=e.size()) return -1;
	return o.size();
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++) cin>>v[i];
		cout<<solve(v)<<endl;
	}
	// your code goes here
	return 0;
}