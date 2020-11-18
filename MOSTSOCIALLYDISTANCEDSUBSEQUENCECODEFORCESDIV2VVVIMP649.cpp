#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
void solve(){
	ll i,j,k,l,n;
	ll a[200001];
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	vector<ll> v;
	for(i=1;i<=n;i++) if(i==1||i==n||(a[i]>a[i-1])!=(a[i]<a[i+1])) v.pb(a[i]);
	cout<<v.size()<<endl;
	for(i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
	
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	solve();
	// your code goes here
	return 0;
}
/*
Given a permutation p of length n, find its subsequence s1, s2, …, sk of length at least 2 such that:

|s1−s2|+|s2−s3|+…+|sk−1−sk| is as big as possible over all subsequences of p with length at least 2.
Among all such subsequences, choose the one whose length, k, is as small as possible.
If multiple subsequences satisfy these conditions, you are allowed to find any of them.

A sequence a is a subsequence of an array b if a can be obtained from b by deleting some (possibly, zero or all) elements.

A permutation of length n is an array of length n in which every element from 1 to n occurs exactly once.

*/