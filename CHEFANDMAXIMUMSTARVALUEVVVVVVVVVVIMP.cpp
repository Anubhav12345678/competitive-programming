#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
const ll maxn = 1000005;
int main() {
	ll i,j,k,l,n,m,t;
	cin>>t;
	while(t--){
		cin>>n;
		// vector<ll> v(n);
		ll mx=0;
		ll a[maxn]={0};
		ll ans=INT_MIN;
		for(i=0;i<n;i++)
		{
			ll tmp;
			cin>>tmp;
			ans= max(ans,a[tmp]);
		    for(j=1;j*j<=tmp;j++){
		    	if(tmp%j==0){
		    		a[j]++;
		    		if((tmp/j)!=j)
		    		a[tmp/j]++;
		    	}
		    }	
		}
		cout<<ans<<endl;
		
		// cout<<mx<<endl;
	}
	// your code goes here
	return 0;
}
/*
You are given a sequence A1,A2,…,AN. For each valid i, the star value of the element Ai is the number of valid indices 
j<i such that Aj is divisible by Ai.

Chef is a curious person, so he wants to know the maximum star value in the given sequence. Help him find it.

*/