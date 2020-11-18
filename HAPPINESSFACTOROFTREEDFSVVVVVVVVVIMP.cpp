
/*

Given an undirected tree with  nodes and  edges, determine the happiness factor of the tree.
 The nodes have a character associated with them. A node is said to be happy if the character associated with
  the node does not appear in the subtree of that node. Happiness factor of the tree is the sum of all the happy nodes in the tree.


*/

#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ; 
vector<int>  adj[100010] ;
int visited[100010] ; 
set<int> h[100010] ;
string s ; 
int ans = 0 ; 
void initialize(){
    for(int i=0;i<100010;i++){
        adj[i].clear();
        visited[i] = 0 ;  
        h[i].clear();
    }
}
void dfs(int start){
    if(visited[start]==1)
         return ;  
    visited[start] = 1 ; 
    for(auto it=adj[start].begin();it!=adj[start].end();it++)
             dfs((*it));
   
   for(auto it=adj[start].begin();it!=adj[start].end();it++){
        for(auto jt=h[(*it)].begin();jt!=h[(*it)].end();jt++){
            h[start].insert((*jt));
        }
    }
    if(h[start].find(s[start])==h[start].end())
         ans++ ; 
    h[start].insert(s[start]);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    initialize();
    int n ; 
    cin >> n ; 
    for(int i=0;i<n-1;i++){
        int x , y ; 
        cin >> x >> y ;
        x-- ; 
        y-- ; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s ; 
    dfs(0);
    cout << ans << endl ; 
}