#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
int main() {
	ll i,j,k,l,n,m,pos=0,cnt=0,s=0;
	map<ll,ll> mp;
	cin>>n;
	ll a[n+1];
	ll x,ans=0;
	mp[0]=1;
	for(i=1;i<=n;i++){
		cin>>x;
		s+=x;
		pos = max(pos,mp[s]);
		ans+=(i-pos);
		mp[s] = i+1;
	}
	cout<<ans;
	// your code goes here
	return 0;
}
/*
Eugene likes working with arrays. And today he needs your help in solving one challenging task.

An array c is a subarray of an array b if c can be obtained from b by deletion of several (possibly, zero or all) elements from
 the beginning and several (possibly, zero or all) elements from the end.

Let's call a nonempty array good if for every nonempty subarray of this array, sum of the elements of this subarray is nonzero.
 For example, array [−1,2,−3] is good, as all arrays [−1], [−1,2], [−1,2,−3], [2], [2,−3], [−3] have nonzero sums of elements.
  However, array [−1,2,−1,−3] isn't good, as his subarray [−1,2,−1] has sum of elements equal to 0.

Help Eugene to calculate the number of nonempty good subarrays of a given array a.

*?