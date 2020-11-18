#include <bits/stdc++.h>
using namespace std;
#define ll long  long

int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		
		for(i=0;i<n;i++) cin>>a[i];
		ll maxi=0;
		for(i=1;i<n;i++){
		  if(a[i]<a[i-1]){
		  	maxi = max(maxi,a[i-1]-a[i]);
		  	a[i] = a[i-1];
		  }	
		}
		cout<<ceil(log2(maxi+1))<<endl;
	}
	// your code goes here
	return 0;
}
/*

You have an array a of length n. For every positive integer x you are going to perform the following operation during the x-th second:

Select some distinct indices i1,i2,…,ik which are between 1 and n inclusive, and add 2x−1 to each corresponding position of a. Formally, aij:=aij+2x−1 for j=1,2,…,k. Note that you are allowed to not select any indices at all.
You have to make a nondecreasing as fast as possible. Find the smallest number T such that you can make the array nondecreasing after at most T seconds.

Array a is nondecreasing if and only if a1≤a2≤…≤an.

You have to answer t independent test cases.
*/