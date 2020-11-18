#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#include<vector>
/*
In a social networking site, people are connected with other people. The whole system appears as a giant connected graph.
 In this question, you are required to answer the total number of people connected at t nodes away from each other 
 (t distance connectivity). For example: Two persons directly connected are at 1 distance connectivity. While the
  two persons having a common contact without having direct connectivity, are at 2 distance connectivity.

First line of input line contains, two integers n and e, where n is the nodes and e are the edges. Next e line will 
contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. Next 
line contains single integer, m, which is number of queries. Next m lines, each have two inputs, one as source node 
and other as a required t distance connectivity which should be used to process query.


*/
ll lvl[100000];
// vector<ll> adj[1000001]
ll bfs(ll root,vector<ll> v[],vector<bool> &vis,ll b){
	ll i,j,k,l;
	queue<ll> q;
	// memset(lvl,0,sizeof(lvl));
	q.push(root);
	vis[root]=true;
	lvl[root]=0;
	ll ans=0;
	while(!q.empty()){
		ll x = q.front();
		q.pop();
		for(i=0;i<v[x].size();i++){
			if(!vis[v[x][i]]){
				vis[v[x][i]] = true;
				lvl[v[x][i]] = lvl[x]+1;
				if(lvl[v[x][i]]==b) ans++;
				else if(lvl[v[x][i]]>b) return ans;
				q.push(v[x][i]);
			}
		}
	}
	return ans;
}
int main(){

	ll i,j,k,l,n,m,e;
	cin>>n>>e;

	// lvl.resize(n+1,0);

	vector<ll> v[n+1];
    for(i=0;i<e;i++){
       ll p,q;
	   cin>>p>>q;
	//    p--;
	//    q--;
       v[p].push_back(q);
	   v[q].push_back(p);
	}

	cin>>m;
	while(m--){
		vector<bool> vis(n+1,false);
		memset(lvl,0,sizeof(lvl));
		ll a,b;
		cin>>a>>b;
		// a--;
		// b--;
		cout<<bfs(a,v,vis,b)<<endl;
	}
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

int level[100000];

int bfs(int root,vector<int> v[],bool visited[],int b){

    queue<int> q;

    q.push(root);

    visited[root]=true;

    int ans=0;

    while(!q.empty()){

        int r=q.front();

        q.pop();

        for(int i=0;i<(int)v[r].size();i++){

            if(!visited[v[r][i]])

            {

                level[v[r][i]]=level[r]+1;

                if(level[v[r][i]]==b)ans++;

                else if(level[v[r][i]]>b)return ans;

                q.push(v[r][i]);

                visited[v[r][i]]=true;

            }

        }

    }

    return ans;

}

int main(){

    int n,m;

    cin>>n>>m;

    vector<int> v[n+1];

    for(int i=0;i<m;i++){

        int a,b;

        cin>>a>>b;

        v[a].push_back(b);

        v[b].push_back(a);

    }

    int t;

    cin>>t;

    bool visited[n+1];

    while(t-->0){

        memset(visited,0,sizeof(visited));

        memset(level,0,sizeof(level));

        int a,b;

        cin>>a>>b;

        cout<<bfs(a,v,visited,b)<<endl;

    }

}

*/




















