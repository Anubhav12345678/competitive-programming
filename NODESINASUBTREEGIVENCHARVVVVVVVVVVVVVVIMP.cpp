#include<bits/stdc++.h>
using namespace std;
/*
You are given a rooted tree that contains n nodes. Each node contains a lowercase alphabet.

You are required to answer q  queries of type u,c where u is an integer and c is a lowercase alphabet. 
The count of nodes in the subtree of the node u containing c is considered as the answer of all the queries. 

Input format

First line: Two space-separated integers  respectively
Second line: A string  of length  (where the  character of  represents the character stored in node )
Next  line: Two space-separated integers  and  denoting an edge between node  and node 
Next  lines: An integer  and a space-separated character  


*/
int cnt[100005][26], n;
vector<int> adj[100005];
string s;
void dfs(int u, int parent)
{
	int i;
	for(i = 0; i < 26; i ++)
	cnt[u][i] = 0;
	cnt[u][s[u - 1] - 'a'] ++;
	for(auto v: adj[u])
	{
		if(v == parent)
		continue;
		dfs(v, u);
		for(i = 0; i < 26; i ++)
		cnt[u][i] += cnt[v][i];
	}
}
int main()
{
	int q, i;
	cin >> n >> q;
	cin >> s;
	for(i = 0; i < n - 1; i ++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	while(q --)
	{
		int u;
		char c;
		cin >> u >> c;
		cout << cnt[u][c - 'a'] << endl;
	}
	return 0;
}
