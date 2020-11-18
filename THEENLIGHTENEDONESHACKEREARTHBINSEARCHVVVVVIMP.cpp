#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*

There are N temples in a straight line and K monks who want to spread their enlightening power to the entire road of temples. All the monks have an enlightenment value, which denotes the range of enlightenment which they can spread in both the directions. Since, they do not want to waste their efficiency on trivial things of the world, they want to keep their range minimum.

Also, when we say that the N temples are in a straight line, we mean that that all the temples lie on something like an X-axis in a graph.
*/
ll solve(vector<ll> &v,ll maxlen,ll k){
	ll ans=1, s=0,prev = v[0]+maxlen;
	k--;
	for(ll i=1;i<v.size();i++){
		if(prev+maxlen>=v[i]) continue;
		if(k==0) return 0;
		prev=v[i]+maxlen;
		k--;
	}
	return 1;
	
}
int main(){
	ll i,j,k,l,n,t;
	cin>>n>>k;
	vector<ll> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	ll lo = 0;
	ll hi = 1e9;
	ll ans=-1,m;
	while(lo<=hi){
		

		 m = (lo+hi)/2;
		ll vv = solve(v,m,k);
		if(solve(v,m,k)&&solve(v,m-1,k)==0) break;
		if(vv==0)
		lo=m+1;
		else
		hi=m-1;
	}
	cout<<m;

}
























