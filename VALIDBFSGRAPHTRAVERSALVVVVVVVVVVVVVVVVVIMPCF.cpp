

/*
The BFS algorithm is defined as follows.

Consider an undirected graph with vertices numbered from 1 to n. Initialize q as a new 
queue containing only vertex 1, mark the vertex 1 as used.
Extract a vertex v from the head of the queue q.
Print the index of vertex v.
Iterate in arbitrary order through all such vertices u that u is a neighbor of v and
 is not marked yet as used. Mark the vertex u as used and insert it into the tail of the queue q.
If the queue is not empty, continue from step 2.
Otherwise finish.
Since the order of choosing neighbors of each vertex can vary, it turns out that there may be multiple sequences which BFS can print.

In this problem you need to check whether a given sequence corresponds to some
 valid BFS traversal of the given tree starting from vertex 1. The tree
  is an undirected graph, such that there is exactly one simple path between any two vertices.


*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define F first
#define S second
typedef vector<pli> vpli;
#define hell 1000000007
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end() 
#define tests int t; cin>>t; while(t--)
#define take(a,b,c) for(b=0;b<c;b++) cin>>a[b];
typedef long long ll;
vector<int> ans,adj[200007];
bool vis[200007];
int inputorder[200007],relorder[200007];	
bool cmp(int a,int b){
	return relorder[a]<relorder[b];
}
int main()
{	
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,x,a,b,i,j;
	cin>>n;
	for(i=0;i<n-1;i++){	
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(i=0;i<n;i++){
		cin>>inputorder[i];
		relorder[inputorder[i]]=i;
	}	
	for(i=1;i<=n;i++)
		sort(all(adj[i]),cmp);
	queue<int> q;		
	q.push(1);	
	memset(vis,false,sizeof(vis));
	while(!(q.empty())){
		queue<int> temp;
		while(!(q.empty())){
			int x= q.front();
			q.pop();
			ans.pb(x);
			vis[x]=true;
			for(j=0;j<adj[x].size();j++)
				if(vis[adj[x][j]]==false)
					temp.push(adj[x][j]);
			}
		q=temp;			
	}
	for(i=0;i<n;i++)
		if(inputorder[i]!=ans[i]){
			cout<<"No"; return 0;}
	cout<<"Yes";		
		
    return 0;
}