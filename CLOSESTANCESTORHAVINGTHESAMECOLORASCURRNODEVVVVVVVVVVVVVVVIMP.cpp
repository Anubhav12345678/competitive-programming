#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<stack>
#include<vector>
#define pb push_back
const ll sz  = 100005;
/*
After a hectic week at work, Mancunian and Liverbird decide to go on a fun weekend camping trip. 
As they were passing through a forest, they stumbled upon a unique tree of N nodes. Vertices are numbered from 1 to N.

Each node of the tree is assigned a color (out of C possible colors). Being bored, they decide to
 work together (for a change) and test their reasoning skills. The tree is rooted at vertex 1. For
  each node, they want to find its closest ancestor having the same color.
*/
ll n,C,col[sz],ans[sz];
vector<ll> g[sz];
stack<ll> st[sz];
void dfs(ll v){
	if(st[col[v]].empty()){
		ans[v]=-1;
	}
	else{
		ans[v]  =st[col[v]].top();
	}

	st[col[v]].push(v);
	for(auto y:g[v]){
		dfs(y);
	}

	st[col[v]].pop();
}

int main(){
   ll i,j,k,l,m;
   cin>>n>>C;
   for(i=2;i<=n;i++){
	   ll p;
	   cin>>p;
	   g[p].pb(i);
   }

   for(i=1;i<=n;i++)
   cin>>col[i];

   dfs(1);

   for(i=1;i<=n;i++)
   cout<<ans[i]<<" ";






	return 0;
}






