#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		ll tot=0,ans=0;
		for(i=0;i<n;i++){
			if(a[i]>=0)
			tot+=a[i];
			else{
				k = min(tot,-a[i]);
				tot-=k;
				a[i]+=k;
			}
		}
		for(i=0;i<n;i++)
		if(a[i]<0)
		ans+=abs(a[i]);
		
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}
/*
You're given an array a of n integers, such that a1+a2+⋯+an=0.

In one operation, you can choose two different indices i and j (1≤i,j≤n), decrement ai by one and increment aj by one.
 If i<j this operation is free, otherwise it costs one coin.

How many coins do you have to spend in order to make all elements equal to 0?

*/