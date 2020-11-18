#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
vector<bool> vis;
vector<vector<ll>> adj;
void dfs(ll i,ll &cntedge,ll &cntvert){
	vis[i]=true;
	cntvert++;
	cntedge+=adj[i].size();
	for(auto x:adj[i])
	 if(!vis[x])
	 dfs(x,cntedge,cntvert);
}
int main(){
	ll n,m,i,j,k,l,p,q,a,b;
	cin>>n>>m;
	vis.resize(n+1,false);
	adj.resize(n+1);
	for(i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		ll cntedge=0,cntvert=0;
		if(!vis[i])
		  dfs(i,cntedge,cntvert);
		if(cntedge!=((cntvert*(cntvert-1)))){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	
}
/*
Bear Limak examines a social network. Its main functionality is that two members 
can become friends (then they can talk with each other and share funny pictures).

There are n members, numbered 1 through n. m pairs of members are friends. Of course, a member can't be a friend with themselves.

Let A-B denote that members A and B are friends. Limak thinks that a network is reasonable
 if and only if the following condition is satisfied: For every three distinct members (X, Y, Z), if X-Y and Y-Z then also X-Z.

For example: if Alan and Bob are friends, and Bob and Ciri are friends, then Alan and Ciri should be friends as well.

Can you help Limak and check if the network is reasonable? Print "YES" or "NO" accordingly, without the quotes.

Input
The first line of the input contain two integers n and m (3 ≤ n ≤ 150 000, ) — the number of members
 and the number of pairs of members that are friends.

The i-th of the next m lines contains two distinct integers a i and b i (1 ≤ a i, b i ≤ n, a i ≠ b i). 
Members a i and b i are friends with each other. No pair of members will appear more than once in the input.


*/