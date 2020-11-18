#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
const ll  maxn  = 100006;
// ll val[maxn];
/*
You are given a tree with  nodes and  edges and an integer . Each node has a label denoted by an integer, . Your task is
 to find the length of the longest path such that label of all the nodes in the path are divisible by .

Length of a path is the number of edges in that path.
*/
// ll cnt[maxn];
vector<ll> cnt, val;
vector<ll> v[maxn];
ll n,k, ans=0;
void dfs(ll st,ll p){
	cnt[st]= (val[st]%k==0);

	ll a=0,b=0;
	for(auto x:v[st]){
		if(x==p) continue;
         dfs(x,st);
		if(cnt[x]>=a){
			b=a;
			a=cnt[x];
		}
		else if(cnt[x]>b)
		b=cnt[x];
	}
	if(cnt[st])
	ans = max(ans,a+b+1);
	if(cnt[st])
	cnt[st] = max(cnt[st]+a,cnt[st]+b); 
}
int   main(){
  
    ll i,j,l,m;
    // memset(cnt,0,sizeof(cnt));
	cin>>n>>k;

	cnt = vector<ll>(n+1,0);
	val = vector<ll>(n+1);
	for(i=1;i<=n;i++){
		cin>>val[i];
		// cnt[i]=;
	}

	for(i=0;i<n-1;i++){
      ll a,b;
	  cin>>a>>b;
	  v[a].pb(b);
	  v[b].pb(a);
	}

	dfs(1,0);

	if(ans!=0) ans-=1;
	cout<<ans<<endl;











	return 0;
}
























