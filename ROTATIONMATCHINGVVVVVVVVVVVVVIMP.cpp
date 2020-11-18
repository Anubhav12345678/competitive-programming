#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
ll solve(ll a[],ll b[],ll n){
	ll i,j,k,l,m;
	map<ll,ll> mp,pos;
	for(i=1;i<=n;i++)
	pos[a[i]]=i;
	for(i=1;i<=n;i++){
		ll cur = pos[b[i]]-i;
		if(cur<0) cur+=n;
		mp[cur]++;
	}
	ll ans=0;
	for(auto it:mp)
	ans = max(ans,it.second);
	return ans;
}
int main() {
	ll i,j,k,l,n;
	cin>>n;
	ll a[n+1],b[n+1];
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	cout<<solve(a,b,n)<<endl;
	// your code goes here
	return 0;
}
/*
After the mysterious disappearance of Ashish, his two favourite disciples Ishika and Hriday, were each left with one half of a
 secret message. These messages can each be represented by a permutation of size n. Let's call them a and b.

Note that a permutation of n elements is a sequence of numbers a1,a2,…,an, in which every number from 1 to n appears exactly once.

The message can be decoded by an arrangement of sequence a and b, such that the number of matching pairs of elements between them
 is maximum. A pair of elements ai and bj is said to match if:

i=j, that is, they are at the same index.
ai=bj
His two disciples are allowed to perform the following operation any number of times:

choose a number k and cyclically shift one of the permutations to the left or right k times.
*/