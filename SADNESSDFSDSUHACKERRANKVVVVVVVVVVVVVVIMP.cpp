#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define ff first
#define se second
//https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/sadness/problem
vector<ll> par,sz;
ll find(ll v){
    if(par[v]==v) return v;
    return find(par[v]);
}
ll join(ll u,ll v){
    ll pu = find(u);
    ll pv = find(v);
    if(pu==pv) return 0;
    ll res=  sz[pu]*sz[pv];
    if(sz[pu]>=sz[pv]){
        sz[pu]+=sz[pv];
        par[pv]=pu;
    }
    else{
        sz[pv]+=sz[pu];
        par[pu]=pv;
    }
    return res;
}

int main() {
    ll n,m;
    cin>>n>>m;
    par.resize(n+1);
    sz.resize(n+1,1);
    for(ll i=0;i<n;i++) par[i]=i;
    vector<ll> ans(m);
    ans[m-1] = (n*(n-1))/2;
    vector<pair<ll,ll>> e;
    for(ll i=0;i<m;i++){
       ll a,b;
        cin>>a>>b;
        a--;
        b--;
        e.push_back({a,b});
    }
    
    for(ll i=m-1;i>=1;i--){
        ans[i-1] = ans[i]-join(e[i].ff,e[i].se);
    }
    
    for(ll i=0;i<m;i++)
        cout<<ans[i]<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
//https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/sadness/problem