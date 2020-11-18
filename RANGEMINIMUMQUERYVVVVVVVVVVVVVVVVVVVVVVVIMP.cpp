#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll MA =  100001;
vector<ll> a(MA,0LL);
vector<ll> sg(4*MA,0LL);
void build(ll ss,ll se,ll node=0){
	if(ss==se){
		sg[node] = a[ss];
		return;
	}
	ll m = ss+(se-ss)/2;
	build(ss,m,2*node+1);
	build(m+1,se,2*node+2);
	sg[node] = min(sg[2*node+1],sg[2*node+2]);
}

ll minrange(ll qs,ll qe,ll ss,ll se,ll node=0){
	
	if(qs>se||qe<ss) return (ll)INT_MAX;
	if(qs<=ss&&se<=qe) return sg[node];
	ll m = ss+(se-ss)/2;
	ll left = minrange(qs,qe,ss,m,2*node+1);
	ll right = minrange(qs,qe,m+1,se,2*node+2);
	return min(left,right);
}
int main() {
	
	ll n,q,l,r;
	cin>>n;
	// memset(sg,0LL,sizeof(sg));
	for(ll i=0;i<n;i++) cin>>a[i];
	build(0,n-1);
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<minrange(l,r,0,n-1)<<endl;
	}
	// your code goes here
	return 0;
}