#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 /*

In a red-blue tree, each vertex is either red or blue and adjacent vertices always have different colours.

You are given a tree with N vertices (numbered 1 through N). It is not necessarily a red-blue tree, but its vertices are
 still coloured red and blue. You may perform the following operation any number of times (including zero): choose two 
 adjacent vertices and swap their colours.

Find the smallest number of operations required to transform the tree into a red-blue tree or determine that it is impossible.

 */
    int n;
    ll ans;
    vector<vector<int>>adj;
    vector<int>parity,color,type1,type2;
 
    void assignParity(int u , int par , int p){
        parity[u]=p;
        for(auto v : adj[u]){
            if(v!=par)
                assignParity(v,u,p^1);
        }
    }
 
    // 0 is red and 1 is blue
    void dfs1(int u ,int par){
        type1[u]=(parity[u]==1 && color[u]==0);
        type2[u]=(parity[u]==0 && color[u]==1);
        for(auto v : adj[u]){
            if(v!=par){
                dfs1(v,u);
                type1[u]+=type1[v];
                type2[u]+=type2[v];
            }
        }
        int mini=min(type1[u],type2[u]);
        type1[u]-=mini;
        type2[u]-=mini;
        ans+=(type1[u]+type2[u]);
    }
    void dfs2(int u ,int par){
        type1[u]=(parity[u]==0 && color[u]==0);
        type2[u]=(parity[u]==1 && color[u]==1);
        for(auto v : adj[u]){
            if(v!=par){
                dfs2(v,u);
                type1[u]+=type1[v];
                type2[u]+=type2[v];
            }
        }
        int mini=min(type1[u],type2[u]);
        type1[u]-=mini;
        type2[u]-=mini;
        ans+=(type1[u]+type2[u]);
    }
 
 
    void solve(){
        cin>>n;
        adj.clear();
        adj.resize(n+1);
        parity.resize(n+1,0);
        color.resize(n+1,0);
        type1.resize(n+1,0);
        type2.resize(n+1,0);
        int a,b;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        string s;
        cin>>s;
        for(int i=0;i<(int)(s.size());i++){
            color[i+1]=(int)(s[i]-'0');
        }
        assignParity(1,-1,0);
        ll result=1e18;
        for(int i=0;i<=1;i++){
            ans=0;
            if(i==0)
                dfs1(1,-1);
            else
                dfs2(1,-1);
            if(type1[1]==type2[1])
                result=min(result,ans);
        }
        if(result==(ll)(1e18)){
            cout<<-1<<"\n";
        }
        else{
            cout<<result<<"\n";
        }
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }