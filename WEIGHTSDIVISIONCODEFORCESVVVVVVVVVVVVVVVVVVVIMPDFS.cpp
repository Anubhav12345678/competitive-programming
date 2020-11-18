#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<set>
#define ff first
#define se second
#define pb push_back
const ll N = 1e5+10;
struct cmp{
   bool operator() (pair<ll,ll> a,pair<ll,ll> b){
   	  return ((a.ff-a.ff/2)*a.se)>((b.ff-b.ff/2)*b.se);
   }	
};

ll sum;
vector<pair<ll,ll>> v[N];
multiset<pair<ll,ll>, cmp> st;
ll dfs(ll z,ll p){
	ll ans=0LL;
	for(pair<ll,ll> x:v[z]){
		if(x.ff==p) continue;
		ll tmp = dfs(x.ff,z); // no of leaves of this edge
		st.insert({x.se,tmp});
		sum+=x.se*tmp;
		ans+=tmp;
	}
	if(!ans) ans=1;
	return ans; // gives total kitni leaves h
}
void solve(){
	ll w,i,j,k,l,n,m;
	cin>>n>>w;
	sum=0;
	st.clear();
	for(i=0;i<=n;i++) v[i].clear();
	for(i=1;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		v[a].pb({b,c});
		v[b].pb({a,c});
	}
	
	dfs(1,0);
	ll ans=0;
	while(sum>w){
		ans++;
		pair<ll,ll>  p = *st.begin();
		st.erase(st.begin());
		sum-=(p.ff*p.se);
		p.ff/=2;
		if(p.ff){
			sum+=(p.ff*p.se);
			st.insert(p);
		}
	}
	cout<<ans<<endl;
	
}
int main() {
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	// your code goes here
	return 0;
}
/*
Easy and hard versions are actually different problems, so we advise you to read both statements carefully.

You are given a weighted rooted tree, vertex 1 is the root of this tree.

A tree is a connected graph without cycles. A rooted tree has a special vertex called the root. 
A parent of a vertex v is the last different from v vertex on the path from the root to the vertex v.
 Children of vertex v are all vertices for which v is the parent. A vertex is a leaf if it has no children.
  The weighted tree is such a tree that each edge of this tree has some weight.

The weight of the path is the sum of edges weights on this path. The weight of the path from the vertex to itself is 0.

You can make a sequence of zero or more moves. On each move, you select an edge and divide its weight by 2 
rounding down. More formally, during one move, you choose some edge i and divide its weight by 2 rounding down (wi:=⌊wi2⌋).

Your task is to find the minimum number of moves required to make the sum of weights of paths from the root 
to each leaf at most S. In other words, if w(i,j) is the weight of the path from the vertex i to the vertex j,
 then you have to make ∑v∈leavesw(root,v)≤S, where leaves is the list of all leaves.

You have to answer t independent test cases.

*/