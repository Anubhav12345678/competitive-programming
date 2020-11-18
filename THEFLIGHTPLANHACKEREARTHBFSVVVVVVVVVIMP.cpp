#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 /*
You are given flights route map of a country consisting of N cities and M undirected flight routes. Each city has an
 airport and each airport can work as layover. The airport will be in two states, Loading and Running. In loading state,
  luggage is loaded into the planes. In the running state, planes will leave the airport for the next city. All the airports
   will switch their states from Loading to Running and vice versa after every T minutes. You can cross a city if its airport
    state is running. Initially, all the airports are in running state. At an airport, if its state is loading, you have to wait
     for it to switch its state to running. The time taken to travel through any flight route is C minutes. Find the lexicographically
      smallest path which will take the minimum amount of time (in minutes) required to move from city X to city Y.

It is guaranteed that the given flight route map will be connected. Graph won't contain multiple edges and self loops. 
A self loop is an edge that connects a vertex to itself.
 */
vector <int> adj[1000000];
int pred[10001], visted[100000];
list<int>l;
 
void BFS(int src,int dest){
    queue <int> q;
    q.push(src);
    visted[src] = 1;
    pred[src] = -1;
    
       
    while(!q.empty()) {
        
    int current = q.front();
    q.pop();
    for(int child: adj[current]){
    if(visted[child] ==0){
        q.push(child);
        visted[child] = 1;
        pred[child] = current;
        if(child==dest){
            return;
        }
    }
        }
    } 
}
 
int main(){
    int t,N,M,X,Y,T,C,U,V;
        cin>>N>>M>>T>>C;
        for(int i =1;i<=N;i++) adj[i].clear(), visted[i] = 0;
        l.clear();
        for(int i = 0;i<M;i++){
             cin>>X>>Y;
            adj[X].push_back(Y);
            adj[Y].push_back(X);
        }
        for(int i=1;i<=N;i++)sort(adj[i].begin(),adj[i].end());
        cin>>U>>V;
 
        BFS(U,V);    
        
        vector<int> path; 
        int crawl = V; 
        path.push_back(crawl); 
        while (pred[crawl] != -1) { 
            path.push_back(pred[crawl]); 
            crawl = pred[crawl]; 
        }
        cout<<path.size()<<endl;
        for (int i = path.size() - 1; i >= 0; i--) 
        cout << path[i] << " ";
    
}