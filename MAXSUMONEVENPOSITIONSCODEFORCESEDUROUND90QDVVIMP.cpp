#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
You are given an array a consisting of n integers. Indices of the array start from zero 
(i. e. the first element is a0, the second one is a1, and so on).

You can reverse at most one subarray (continuous subsegment) of this array. Recall that the subarray
 of a with borders l and r is a[l;r]=al,al+1,…,ar.

Your task is to reverse such a subarray that the sum of elements on even positions of the resulting
 array is maximized (i. e. the sum of elements a0,a2,…,a2k for integer k=⌊n−12⌋ should be maximum possible).

You have to answer t independent test cases.

*/
ll kadane(vector<ll> &v){
	ll i,j,k,l,n=v.size();
	ll maxtillhere=0,maxsofar=0;
	for(i=0;i<n;i++){
		maxtillhere+=v[i];
		if(maxtillhere<0) maxtillhere=0;
		maxsofar = max(maxtillhere,maxsofar);
	}
	return maxsofar;
}

ll solve(vector<ll> &v){
	ll i,j,k,l,n=v.size();
	ll se=0;
	for(i=0;i<n;i++){
		if(i%2==0) se+=v[i];
	}
	
	vector<ll> v1,v2;
	for(i=0;i<n-1;i+=2)
	v1.push_back(v[i+1]-v[i]);
	for(i=1;i<n-1;i+=2)
	v2.push_back(v[i]-v[i+1]);
	ll s1 = kadane(v1);
	ll s2 = kadane(v2);
	return se+max(0LL,max(s1,s2));
}
int main() {
	
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++) cin>>v[i];
		cout<<solve(v)<<endl;
	}
	// your code goes here
	return 0;
}