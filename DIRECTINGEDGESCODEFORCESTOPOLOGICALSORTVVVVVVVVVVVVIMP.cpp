#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<set>
#define pb push_back
#define ff first
#define se second
/*
You are given a graph consisting of n vertices and m edges. It is not guaranteed that the given graph 
is connected. Some edges are already directed and you can't change their direction. Other edges are 
undirected and you have to choose some direction for all these edges.

You have to direct undirected edges in such a way that the resulting graph is directed and acyclic
 (i.e. the graph with all edges directed and having no directed cycles). Note that you have to direct all undirected edges.

You have to answer t independent test cases.
*/
#include<map>
vector<ll> tree[200001];
vector<ll> sorted;
bool poss;
void toposort(ll i,vector<bool> &vis,set<ll> &ancestor){
	vis[i]=true;
	ancestor.insert(i);
	for(auto child: tree[i]){
		if(ancestor.find(child)!=ancestor.end())
		{
			poss=0;
			return;
		}
		if(!vis[child]){
			toposort(child,vis,ancestor);
		}
	}
	ancestor.erase(i);
	sorted.pb(i);
}
int main() {
	
	ll n,m,i,j,k,l,p,q,a,b,t,x,y;
	cin>>t;
	while(t--){
		sorted.clear();
		cin>>n>>m;
		vector<pair<ll,ll>> undir,dir;
		poss=1;
		for(i=0;i<n+1;i++) tree[i].clear();
		for(j=0;j<m;j++){
			ll typ;
			cin>>typ>>x>>y;
			if(typ==0)
			undir.pb({x,y});
			else{
				tree[x].pb(y);
				dir.pb({x,y});
			}
		}
		vector<bool> vis(n+1,false);
		for(i=1;i<=n;i++){
			set<ll> ancestor;
			if(!vis[i])
			  toposort(i,vis,ancestor);
		}
		// sorted  has sorted according to priority
		map<ll,ll> ind;
		for(i=0;i<sorted.size();i++)
		ind[sorted[i]] = i;
		
		if(poss){
			cout<<"YES"<<endl;
			for(auto p:dir){
				cout<<p.ff<<" "<<p.se<<endl;
			}
			for(auto p:undir){
				x = ind[p.ff];
				y = ind[p.se];
				if(x>y)
				cout<<p.ff<<" "<<p.se<<endl;
				else 
				cout<<p.se<<" "<<p.ff<<endl;
			}
		}
		else
		  cout<<"NO\n";
		
		
	}
	// your code goes here
	return 0;
}