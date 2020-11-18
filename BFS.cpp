//BFS traversal of a graph complexity O(V+E)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<list>
#include<queue>
#define pb push_back
#define pf pop_front
#include<iterator>
class graph{
	ll v;//no of vertices
	list<ll> *adj;//pointer to an array containg adjacency list
	public:
	  graph(ll v);
	  void addedge(ll v,ll w);//add w to the adjacency list of v
	  void BFS(ll s);// to do bfs traversal of graph starting fro  node s
};//semi colon is necessary as class is not a datatype and above is not a func

graph::graph(ll v)
{
	this->v = v;
	adj = new list<ll>[v];
}
/* only constructor doesnt need type all other fun of class require a datatype */
void graph::addedge(ll v,ll w)
{
	adj[v].pb(w);//add w as adjacent node of v
}

void graph::BFS(ll s)
{
	ll i;
	bool visited[v];
	for(i=0;i<v;i++)
	visited[i] = false;
	
	list<ll> q;
	
	q.pb(s);
	// cout<<s<<" ";
	visited[s] = true;
	list<ll>::iterator it;
	while(!q.empty())
	{
		s = q.front();
		cout<<s<<" ";
		q.pf();
		
		for(it = adj[s].begin();it!=adj[s].end();++it)
		{
			if(!visited[*it])
			{
				visited[*it] = true;
				q.pb(*it);
			}
		}
	}
}
	

int main() {
	
	graph g(4); 
    g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(1); 
	// your code goes here
	return 0;
}
/* OUTPUT
 Following is Breadth First Traversal (starting from vertex 1) 
1 2 0 3 
 
*/