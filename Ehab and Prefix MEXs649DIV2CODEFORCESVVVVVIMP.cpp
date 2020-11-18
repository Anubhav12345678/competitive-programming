#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<set>
/*

Given an array a of length n, find another array, b, of length n such that:

for each i (1≤i≤n) MEX({b1, b2, …, bi})=ai.
The MEX of a set of integers is the smallest non-negative integer that doesn't belong to this set.

If such array doesn't exist, determine this.
*/void solve(){
	ll i,j,k,l,n;
	cin>>n;
	vector<ll> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	set<ll> s;
	for(i=0;i<2*n;i++) s.insert(i);
	bool f=1;
	for(i=0;i<n;i++){
		if(i<n-1&&v[i]>v[i+1]) f=0;
		s.erase(v[i]);
	}
	
	if(f==0)
	{
		cout<<"-1"<<endl;
		return;
	}
	vector<ll> ans;
	for(i=0;i<n;i++){
		ans.pb(*s.begin());
		s.erase(*s.begin());
		if(i<n-1&&v[i]!=v[i+1])
		s.insert(v[i]);
	}
	for(i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	cout<<endl;
}
int main() {
	ll t,n,k,i,j,l;
	// cin>>t;
	t=1;
	
	while(t--)
	solve();
	// your code goes here
	return 0;
}