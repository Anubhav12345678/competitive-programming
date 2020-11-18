#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
vector<ll> sg[4*30001];
ll val[30001];
void merge(vector<ll> &a,vector<ll> &b,vector<ll> &c){
	ll i=0,j=0;
	while(i<a.size()&&j<b.size()){
		if(a[i]<b[j]) c.pb(a[i++]);
		else c.pb(b[j++]);
	}
	while(i<a.size())
	c.pb(a[i++]);
	while(j<b.size())
	c.pb(b[j++]);
}
void build(ll ss,ll se,ll node=1){
	if(ss==se){
		sg[node].pb(val[ss]);
		return;
	}
	ll mid = (ss+se)/2;
	build(ss,mid,2*node);
	build(mid+1,se,2*node+1);
	merge(sg[2*node],sg[2*node+1],sg[node]);
}

ll query(ll qs,ll qe,ll ss,ll se,ll k,ll node=1){
	if(qs>se||qe<ss)
	return 0;
	if(qs<=ss&&qe>=se){
		return sg[node].end()-upper_bound(sg[node].begin(),sg[node].end(),k);
	}
	
	ll mid = (ss+se)/2;
	ll x = query(qs,qe,ss,mid,k,2*node);
	ll y = query(qs,qe,mid+1,se,k,2*node+1);
	return x+y;
}
int main() {
	
	ll i,j,k,l,n,r,q;
	cin>>n;
	for(i=1;i<=n;i++) cin>>val[i];
	build(1,n);
	cin>>q;
	while(q--){
		cin>>l>>r>>k;
		cout<<query(l,r,1,n,k)<<endl;
	}
	// your code goes here
	return 0;
}