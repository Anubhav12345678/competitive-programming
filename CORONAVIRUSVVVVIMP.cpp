#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#include<queue>
// #include<par.
bool isval(ll n,ll i,ll j)
{
    return i>=0&&i<n&&j>=0&&j<n;
}
int main() {
    ll i,j,k,l,n,t,cnt=0,m;
    cin>>n;
    ll a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    cin>>m;
    // pair<ll,ll> p[m];
    k=0;
    queue<pair<ll,ll>> q;
    for(i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        // cout<<"x = "<<x<<" y = "<<y<<endl;
        x--;
        y--;
        if(a[x][y]!=0)
        {
            // p[k].first=x;
            // p[k].second=y;
            q.push({x,y});
            
            // k++;
        }
    }
    bool vis[n][n];
    // memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            vis[i][j]=false;
    
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    
    while(!q.empty())
    {
        pair<ll,ll> p = q.front();
        q.pop();
        // cout<<"p.first =  "<<p.first<<" p.second = "<<p.second<<endl;
        if(vis[p.first][p.second]||a[p.first][p.second]==0)
            continue;
        ll x = p.first;
        ll y = p.second;
        cnt++;
        // cout<<"cnt = "<<cnt<<endl;
        vis[x][y]=1;
        for(i=0;i<4;i++)
        {
            ll nx = x+dx[i];
            ll ny = y+dy[i];
            if(isval(n,nx,ny)&&!vis[nx][ny])
            {
                // cout<<"nx = "<<nx<<" ny = "<<ny<<endl;
                q.push({nx,ny});
            }
        }
    }
    cout<<cnt<<endl;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
