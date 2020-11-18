#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n){
	ll i,j,k,l;
	
	ll ans=0;
	k=0;
	for(i=2;i<n;i++){
		if(a[i]^(a[i-1]+a[i-2])) k=0;
		else
		ans = max(ans,++k);
	}
	
	return min(ans+2,n);
}
int main() {
	ll i,j,k,l,n;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++) cin>>a[i];
	cout<<solve(a,n);
	// your code goes here
	return 0;
}
/*
You have array a 1, a 2, ..., a n. Segment [l, r] (1 ≤ l ≤ r ≤ n) is good if a i = a i - 1 + a i - 2, for all i (l + 2 ≤ i ≤ r).

Let's define len([l, r]) = r - l + 1, len([l, r]) is the length of the segment [l, r]. Segment [l 1, r 1], is longer than segment [l 2, r 2], if len([l 1, r 1]) > len([l 2, r 2]).

Your task is to find a good segment of the maximum length in array a. Note that a segment of length 1 or 2 is always good.

*/