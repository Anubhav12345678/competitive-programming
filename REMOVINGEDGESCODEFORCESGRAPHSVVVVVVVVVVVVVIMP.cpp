#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<set>
#include<map>
#define pb push_back
#define N 200010
#include<queue>
#define ff first
#define se second
ll n,k,a,b,p,q,m,t,i,j,l;
ll in[N];
/*
You are given a tree (connected graph without cycles) consisting of n vertices. 
The tree is unrooted — it is just a connected undirected graph without cycles.

In one move, you can choose exactly k leaves (leaf is such a vertex that is connected
 to only one another vertex) connected to the same vertex and remove them with edges
  incident to them. I.e. you choose such leaves u1,u2,…,uk that there are edges (u1,v),
   (u2,v), …, (uk,v) and remove these leaves and these edges.

Your task is to find the maximum number of moves you can perform if you remove leaves optimally.

You have to answer t independent test cases.
*/
int main() {
	cin>>t;
	while(t--){
		// vector<ll> in();
		scanf("%lld %lld",&n,&k);
		vector<ll> in(n+10,0);
		vector<ll> leaf(n+10,0);
		map<ll,map<ll,ll>> mp;
		for(i=1;i<n;i++){
			scanf("%lld %lld",&a,&b);
			mp[a][b]=1;
			mp[b][a]=1;
			in[a]++;
			in[b]++;
		}
		queue<ll> q;
		ll ct=0;
		for(i=1;i<=n;i++)
		if(in[i]==1)  q.push(i); 
		while(!q.empty()){
			i = q.front();
			q.pop();
			if(!mp[i].empty()){
			  ll x = mp[i].begin()->ff;
			  mp[x].erase(i);
			  leaf[x]++;
			  if(leaf[x]%k==0) ct++;
			  if(leaf[x]==(in[x]-1)&&(in[x]-1)%k==0) q.push(x); 
			}
		}
		cout<<ct<<endl;
	}
	// your code goes here
	return 0;
}