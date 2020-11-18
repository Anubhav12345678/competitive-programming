#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define se second
#include<vector>
/*
Mr. Kitayuta has just bought an undirected graph consisting of n vertices and m edges. 
The vertices of the graph are numbered from 1 to n. Each edge, namely edge i, has a color c i, connecting vertex a i and b i.

Mr. Kitayuta wants you to process the following q queries.

In the i-th query, he gives you two integers — u i and v i.

Find the number of the colors that satisfy the following condition: the edges of that
 color connect vertex u i and vertex v i directly or indirectly.

*/
vector<pair<ll,ll> > g[105];
ll n,m;
vector<bool> vis(105);
bool dfs(ll v,ll col,ll dst){
	vis[v]=1;
	if(v==dst) return 1;
	for(auto y = 0;y<g[v].size();y++){
		pair<ll,ll> p = g[v][y];
		if(p.se==col&&!vis[p.ff]){
		if(dfs(p.ff,col,dst)) return  true;
		}
	}
	return false;
}
int main() {
	
	// ll n,m;
	ll i,j,k,l,a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		a--;
		b--;
		c--;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	
	ll q;
	cin>>q;
	while(q--){
	 ll u,v;
	 cin>>u>>v;
	 u--;
	 v--;
	 ll ans=0;
	 for(i=0;i<100;i++){
	 	// cin>>u>>v;
	 	for(j=0;j<vis.size();j++) vis[j]=false;
	 	if(dfs(u,i,v)) ans++;
	 }
	 cout<<ans<<endl;
	}
	
	// your code goes here
	return 0;
}