#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
int main(){


/*
You are given an array A of length N. You have to choose a subset S from given array A, such that average of S is less than K. You need to print the maximum possible length of S.

Input format : 

The first line of each input contains  N, length of array A.
Next line contains N space separated elements of array A.
Next line of input contains an integer Q, Number of queries.
Each following Q  lines contains a single integer K.

*/
	ll i,j,k,l,n,q;
	cin>>n;
	// vector<ll> v(n);
	ll a[n+1];
	a[0]=0;
	for(i=1;i<=n;i++) cin>>a[i];
	ll pre[n+1];
	pre[0]=0;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	pre[i] = pre[i-1]+a[i];
	vector<double> ar;
	for(i=1;i<=n;i++) ar.pb(pre[i]/(double)(i));
	cin>>q;
	while(q--){
		cin>>k;
		ll idx = lower_bound(ar.begin(),ar.end(),k)-ar.begin();
		cout<<idx<<endl;
	}
   return 0;
}






















