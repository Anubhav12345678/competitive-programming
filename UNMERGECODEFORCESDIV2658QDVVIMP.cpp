#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*
Let a and b be two arrays of lengths n and m, respectively, with no elements in common. We can define a new array merge(a,b)
 of length n+m recursively as follows:

If one of the arrays is empty, the result is the other array. That is, merge(∅,b)=b and merge(a,∅)=a. In particular, merge(∅,∅)=∅.
If both arrays are non-empty, and a1<b1, then merge(a,b)=[a1]+merge([a2,…,an],b). That is, we delete the first element a1 of a,
 merge the remaining arrays, then add a1 to the beginning of the result.
If both arrays are non-empty, and a1>b1, then merge(a,b)=[b1]+merge(a,[b2,…,bm]). That is, we delete the first element b1 of b,
 merge the remaining arrays, then add b1 to the beginning of the result.
This algorithm has the nice property that if a and b are sorted, then merge(a,b) will also be sorted. For example, it is used as
 a subroutine in merge-sort. For this problem, however, we will consider the same procedure acting on non-sorted arrays as well.
  For example, if a=[3,1] and b=[2,4], then merge(a,b)=[2,3,1,4].

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation,
 but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

There is a permutation p of length 2n. Determine if there exist two arrays a and b, each of length n and with no elements in common, 
so that p=merge(a,b).
*/
bool solve(vector<ll> &v,ll x){
	ll i,j,k,l,n=v.size();
	bool dp[n+1][x+1];
	memset(dp,0,sizeof(dp));
	for(i=0;i<=n;i++)
	dp[i][0]=1;
	for(i=1;i<=x;i++)
	dp[0][i]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=x;j++){
			if(j>=v[i-1])
			dp[i][j] = dp[i-1][j]||dp[i-1][j-v[i-1]];
			else
			dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][x];
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> v(2*n);
		for(i=0;i<2*n;i++) cin>>v[i];
		vector<ll> b;
		for(i=0;i<2*n;){
			ll tp=0;
			ll w = v[i];
			while(v[i]<=w&&i<2*n) i++, tp++;
			b.pb(tp);
		}
		if(solve(b,n))
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	
	
	// your code goes here
	return 0;
}