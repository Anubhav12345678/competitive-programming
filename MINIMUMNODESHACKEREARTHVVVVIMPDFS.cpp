#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
const ll maxn = 100001;
/*
You are given a tree with N nodes and each node has some value assigned to it. Now you are given Q tasks of the form X K.
For each task, you have to find the path starting from X such that sum of nodes in the path is at least K and it contains minimum number of nodes. If such path exists, print the count of nodes in the path, else print -1.

*/
vector<vector<ll>> adj;
ll ans,k;
vector<ll> vec;
void dfs(ll src,ll par,ll sum,ll cnt){
	sum+=vec[src];
	cnt++;
	if(sum>=k) ans = min(ans,cnt);
	for(ll i=0;i<adj[src].size();i++){
		ll nxt = adj[src][i];
		if(nxt==par) continue;
		dfs(nxt,src,sum,cnt);
	}
}
int main(){
	ll i,j,l,n,m,q,u,v;
	cin>>n>>q;
	vec.resize(n+1);
	for(i=1;i<=n;i++) {
		ll x;
		cin>>x;
		vec[i]=x;
	}
	adj.clear();
	adj.resize(n+1);
	for(i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    
	ll src;
	while(q--){
		cin>>src>>k;
		ans = INT_MAX;
		dfs(src,0,0,0);
		if(ans==INT_MAX) ans=-1;
		cout<<ans<<endl;
	}

	return 0;

	


}






















