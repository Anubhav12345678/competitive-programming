#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
bool fun(ll m,vector<ll> &v,ll k){
	ll i,j,l,n=v.size(),tot=0;
	for(i=0;i<n;i++){
		if(v[i]<=m)
		continue;
		tot+=(v[i]/m);
	}
	return tot<=k;
	
}
ll solve(vector<ll> &v,ll k){
	ll i,j,l,n,m;
	n = v.size();
	if(k==0) return *max_element(v.begin(),v.end());
	i=1;
	j = 1e9+7;
	while(i<j){
		ll m = i+(j-i)/2;
		if(fun(m,v,k))
		j=m;
		else
		i=m+1;
	}
	
	return i;
}
int main() {
	ll n,k,i,j,l;
	cin>>n>>k;
	vector<ll> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	cout<<solve(v,k);
	// your code goes here
	return 0;
}
/*
We have 
N
 logs of lengths 
A
1
,
A
2
,
⋯
A
N
.

We can cut these logs at most 
K
 times in total. When a log of length 
L
 is cut at a point whose distance from an end of the log is 
t
 
(
0
<
t
<
L
)
, it becomes two logs of lengths 
t
 and 
L
−
t
.

Find the shortest possible length of the longest log after at most 
K
 cuts, and print it after rounding up to an integer.


*/