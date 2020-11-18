#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
void bfs(vector<vector<int>> &graph, vector<int> &visited, int source){
	queue<int> Q;
	Q.push(source);
	visited[source] = source;
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		for(int i=0; i<graph[node].size(); i++){
			if(visited[graph[node][i]]==-1){
				Q.push(graph[node][i]);
				visited[graph[node][i]] = source;
			}
		}
	}
}
 
int main() {
	// your code goes here
	int N, M;
	cin>>N>>M;
	vector<vector<int>> graph(N);
	for(int i=0; i<M; i++){
		int x, y;
		cin>>x>>y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int result = 0;
	vector<int> visited(N, -1);
	for(int i=0; i<N; i++){
		if(visited[i]==-1){
			bfs(graph, visited, i);
			int count = 0;
			for(int j=0; j<N; j++){
				if(visited[j]==i){
					count++;
				}
			}
			result += ceil(sqrt(count));
		}
	}
	cout<<result;
	return 0;
}
/*

Nuclear Rods
A core meltdown has occurred at the Fubaru nuclear plant. There are
n nuclear fuel rods that are damaged and need to be removed using
specialized radiation-hardened robotic equipment
with solid-lead isolation chambers. Remote imaging has already
uniquely identified every damaged fuel rod and assigned it a number
between 1 and n. The imaging data also records which fuel rods were
fused to each other during the meltdown. Every recovery sortie by the
robot can pick up one set of nuclear fuel rods that are directly or
indirectly fused to each other.
The recovery costs per sortie are proportional to the square root of the
number of fused rods recovered. So the cost is K to recover K rods.
Isolation chambers are available for all positive integer costs (1, 2, 3, …).
An isolation chamber can be used multiple times, and each use will
incur the same cost. The robot can also recover a lower number of rods
than a chamber's capacity on a sortie.
Find the minimal cost to recover all the radioactive rods by completing
the given function.

*/