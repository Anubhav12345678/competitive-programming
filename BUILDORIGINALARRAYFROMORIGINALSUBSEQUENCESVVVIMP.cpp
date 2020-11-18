// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to add edge to graph 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
} 

// Function to calculate indegrees of all the vertices 
void getindeg(vector<int> adj[], int V, vector<int>& indeg) 
{ 
	// If there is an edge from i to x 
	// then increment indegree of x 
	for (int i = 0; i < V; i++) { 
		for (auto x : adj[i]) { 
			indeg[x]++; 
		} 
	} 
} 

// Function to perform topological sort 
vector<int> topo(vector<int> adj[], int V, vector<int>& indeg) 
{ 
	queue<int> q; 

	// Push every node to the queue 
	// which has no incoming edge 
	for (int i = 0; i < V; i++) { 
		if (indeg[i] == 0) 
			q.push(i); 
	} 
	vector<int> res; 
	while (!q.empty()) { 
		int u = q.front(); 
		q.pop(); 
		res.push_back(u); 

		// Since edge u is removed, update the indegrees 
		// of all the nodes which had an incoming edge from u 
		for (auto x : adj[u]) { 
			indeg[x]--; 
			if (indeg[x] == 0) 
				q.push(x); 
		} 
	} 
	return res; 
} 

// Function to generate the array 
// from the given sub-sequences 
vector<int> makearray(vector<vector<int> > v, int V) 
{ 

	// Create the graph from the input sub-sequences 
	vector<int> adj[V]; 
	for (int i = 0; i < v.size(); i++) { 
		for (int j = 0; j < v[i].size() - 1; j++) { 

			// Add edge between every two consecutive 
			// elements of the given sub-sequences 
			addEdge(adj, v[i][j], v[i][j + 1]); 
		} 
	} 

	// Get the indegrees for all the vertices 
	vector<int> indeg(V, 0); 
	getindeg(adj, V, indeg); 

	// Get the topological order of the created graph 
	vector<int> res = topo(adj, V, indeg); 
	return res; 
} 

// Driver code 
int main() 
{ 
	// Size of the required array 
	int n = 10; 

	// Given sub-sequences of the array 
	vector<vector<int> > subseqs{ { 9, 1, 2, 8, 3 }, 
								{ 6, 1, 2 }, 
								{ 9, 6, 3, 4 }, 
								{ 5, 2, 7 }, 
								{ 0, 9, 5, 4 } }; 

	// Get the resultant array as vector 
	vector<int> res = makearray(subseqs, n); 

	// Printing the array 
	for (auto x : res) { 
		cout << x << " "; 
	} 

	return 0; 
} 
