#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll solve(vector<ll> &v){
	ll i,j,k,n=v.size();
	vector<ll> left(3005,0);
	ll ans=0;
	for(j=0;j<n;j++){
		vector<ll> right(3005,0);
		for(k=n-1;k>j;k--){
			ans+=left[v[k]]*right[v[j]];
			right[v[k]]++;
		}
		left[v[j]]++;
	}
	return ans;
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
/*
You are given an array a1,a2…an. Calculate the number of tuples (i,j,k,l) such that:

1≤i<j<k<l≤n;
ai=ak and aj=al;
*/