#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
void dfs(vector<ll> v[],ll s,bool vis[])
{
	vis[s]=true;
	for(ll i=0;i<v[s].size();i++)
	if(!vis[v[s][i]])
	dfs(v,v[s][i],vis);
}
int main() {
	ll n,i,j,k,l,t;
	cin>>n>>t;
	vector<ll> v[n];
	for(i=0;i<n-1;i++)
	{
		cin>>k;
		v[i].push_back(i+k);
	}
	bool vis[n];
	memset(vis,false,sizeof(vis));
	dfs(v,0,vis);
	if(vis[t-1])cout<<"YES\n";
	else cout<<"NO\n";
	// your code goes here
	return 0;
}