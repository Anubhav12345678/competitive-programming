#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<map>
ll solve(vector<ll> &v){
	ll i,j,k,l,n=v.size();
	map<ll,ll> mp;
	ll s=0,ans=0;
	// mp[0]=1;
	for(i=0;i<n;i++){
		s+=v[i];
		if(s==0) ans++;
		ans+=mp[s];
		mp[s]++;
	}
	return ans;
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> v(n);
		string s;
		cin>>s;
		for(i=0;i<n;i++) v[i] = (s[i]-'0'-1);
		cout<<solve(v)<<endl;
	}
	// your code goes here
	return 0;
}
/*
You are given an array a1,a2,…,an consisting of integers from 0 to 9. A subarray al,al+1,al+2,…,ar−1,ar is good if
 the sum of elements of this subarray is equal to the length of this subarray (∑i=lrai=r−l+1).

For example, if a=[1,2,0], then there are 3 good subarrays: a1…1=[1],a2…3=[2,0] and a1…3=[1,2,0].

Calculate the number of good subarrays of the array a.
*/