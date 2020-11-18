#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#include<limits.h>
#define V 9
#define inf INT_MAX
ll mindist(ll dist[],bool sptset[])//spanning tree set to check whether vertex is in sptset or not
{
	ll mini = INT_MAX;
	ll min_ind = -1;
	for(ll i=0;i<V;i++)
	{
		if(sptset[i]==false&&dist[i]<mini)
		{
			mini = dist[i];
			min_ind = i;
		}
	}
	return min_ind;
}

void printsol(ll dis[])//dis[i]denotes shortest dis from src to i
{
	cout<<"Vertex	Dist\n";
  	for(ll i=0;i<V;i++)
  	{
  		cout<<i<<" "<<dis[i]<<"\n";
  	}
}
//fun to implement dijkstra algo to determine min dis of all other vertices from the source
void dijkstra(ll graph[][V],ll src)

{
	bool sptset[V];
	memset(sptset,false,sizeof(sptset));
	ll i=0,dist[V];;
	for(i=0;i<V;i++)
	{
	dist[i] = INT_MAX;
	sptset[i] = false;
	}
	dist[src] = 0;
	ll u,v;
	for(ll count=0;count<V-1;count++)
	{
		// Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
	  u = mindist(dist,sptset);
	  sptset[u] = true;
	  for(v = 0;v<V;v++)
	  {
	    if(dist[u]!=inf&&sptset[v]==false&&graph[u][v]&&(dist[u]+graph[u][v]<dist[v]))
	    dist[v] = dist[u]+graph[u][v];
	  }
	  
	}
	printsol(dist);
}
int main() {
	/* Let us create the example graph discussed above */
   ll graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(graph, 0); 
   
    return 0; 
	// your code goes here
	return 0;
}
// Another method
void dijkstra(vector<vector<int>> graph, int src, int V)
{
   queue<int> q;
   vector<int> dist(V,INT_MAX/2);
   int i,j,k,l,u,v;
   dist[src]=0;
   q.push(src);
   while(!q.empty())
   {
       int tmp = q.front();
       q.pop();
       for(i=0;i<V;i++)
       {
           if(dist[tmp]+graph[tmp][i]<dist[i])
           {
           dist[i] = min(dist[i],dist[tmp]+graph[tmp][i]);
           q.push(i);
           }
       }
   }
   for(auto i:dist)
   cout<<i<<' ';
    // Your code here
}