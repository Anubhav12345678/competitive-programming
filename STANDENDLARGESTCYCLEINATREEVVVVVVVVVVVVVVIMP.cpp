#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
const ll N = 1e5+5;
vector<ll> g[N];
bool vis[N];
ll st=-1;
ll tot=0;
/*
You are given a tree of n nodes and n-1 edges. Now you need to select two nodes a and b in the tree such that the
 cycle that will be formed after adding an edge between the two nodes a and b, its length should be maximum. If 
 there are more than one possible answers, you can output any of them.


It's about the Diameter of Tree.
To calculate the diameter of a tree is based on two depth-first
searches. First, we choose an arbitrary node *a* in the tree and find the
farthest node *b* from *a*. Then, we find the farthest node *c* from *b*. The diameter
of the tree is the distance between *b and c*.

*/
void dfs(ll x,ll len){
	if(len>tot){
		tot=len;
		st=x;
	}
	vis[x]=true;
	for(auto y:g[x]){
		if(!vis[y]){
			dfs(y,len+1);
		}
	}
	return;
}

int main(){
   ll i,j,k,l,n;
   memset(vis,false,sizeof(vis));
   cin>>n;
   for(i=0;i<n-1;i++){
	   ll u,v;
	   cin>>u>>v;
	   g[u].pb(v);
	   g[v].pb(u);
   }
  
   st=-1;
   dfs(1,1);
   tot=0;
   cout<<st<<" ";
   memset(vis,false,sizeof(vis));
   dfs(st,1);
   cout<<st<<" ";






	return 0;
}







