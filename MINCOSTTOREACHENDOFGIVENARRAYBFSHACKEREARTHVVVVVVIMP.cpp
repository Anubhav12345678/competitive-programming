#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<queue>
/*
You are standing at position 1. From position i, you can walk to i+1 or i-1 with cost 1. From position i, you can travel to without
 any cost to p[i] (p is a permutation of numbers 1......n). You have to reach position n. Determine the minimum possible cost.

Input format

First line:  denotes the number of test cases ()
For each test case:
First line:  ()
Second line:  integers where the  integer is 
Note: It is guaranteed that  is a permutation.

*/
ll solve(vector<ll> &v,ll n){
	ll  i,j,k,l;
    

	return -1;

}

int main(){

  ll i,j,k,l,n,t;
  cin>>t;
  while(t--){
	  cin>>n;
	  vector<ll> v(n+1);
	  vector<pair<ll,ll>> adj[n+1];
	  for(i=1;i<=n;i++) adj[i].clear();
	  deque<pair<ll,ll>> q;
	  for(i=1;i<=n;i++){ 
		  cin>>v[i];
		  if(i!=v[i]) adj[i].push_back({v[i],0});
	  }

	  for(i=1;i<=n;i++){
		  if(i>1) adj[i].push_back({i-1,1});
		  if(i<n) adj[i].push_back({i+1,1});
	  }

	  ll d[n+1];
	  for(i=1;i<=n;i++) d[i]=INT_MAX;
	  d[1] =0;
	  q.push_front({0,1});
	  while(!q.empty()){
		  auto p = q.front();
		  q.pop_front();
		  ll x=  p.second;
		  ll w =  p.first;
		  if(d[x]<w) continue;
		  if(x== n) break;
		  for(auto &y:adj[x]){
			  if(d[y.first]>y.second+w){
				  if(y.second==0) q.push_front({w,y.first});
				  else
				  q.push_back({w+y.second,y.first});
				  d[y.first] = w+y.second;
			  }
		  }
	  }
	  cout<<d[n]<<endl;
  }










	return 0;
}
















