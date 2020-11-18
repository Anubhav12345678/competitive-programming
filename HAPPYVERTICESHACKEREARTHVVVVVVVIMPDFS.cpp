#include <bits/stdc++.h> 

using namespace std; 

#define PB push_back 
#define NL '\n' 
#define PI 2.0*acos(0.0) 
#define MOD 1e9+7 
#define FOR(i, j, n)    for(ll i = j; i < n; i++) 
#define RFOR(i, j, n)    for(ll i = j; i >= n; i--) 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

typedef long long int ll; 
typedef unsigned long long ull; 
typedef long double ld; 
/*
You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 
or more children. In any connected component of the graph,vertex with the lowest value in that component serves as
 the master parent.
A vertex is called happy if it has more children than its parent. Count the number of happy vertices in the given 
graph.The graph has no cycles or self loops.

Input Format:

First line consists of two space separated integers denoting N and M and the following M lines consist of two 
space separated integers X and Y denoting there is an edge between vertices X and Y.


*/
vector <ll> Graph[100005]; 
ll color[100005],child[100005],parent[100005]; 

void dfs(ll v) { 
   color[v] = 1; 
   for(auto u : Graph[v]) { 
       if(color[u] == 0) { 
           parent[u] = v; 
           child[v]++; 
           dfs(u); 
       } 
   } 
   color[v] = 2; 
} 

int main() { 
   ll n, m, a, b, ans = 0; 
   cin >> n >> m; 
   while(m--){ 
       cin >> a >> b; 
       Graph[a].PB(b); 
       Graph[b].PB(a); 
   } 
   FOR(i, 1, n+1){ 
       dfs(i); 
   } 
   FOR(i, 1, n+1){ 
       if(parent[i] != 0){ 
           if(child[parent[i]] < child[i]) ans++; 
       } 
   } 
   cout << ans << endl; 
}