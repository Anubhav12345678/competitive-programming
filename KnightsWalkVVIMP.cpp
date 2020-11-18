#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
struct cell
{
    ll r,c,dis;
    cell() {}
    cell(ll r,ll c,ll dis): r(r), c(c), dis(dis) {}
};
bool issafe(ll r,ll c,ll n,ll m)
{
    return r>=1&&c>=1&&r<=n&&c<=m;
}
int main() {
    ll x[] = {-2,-2,2,2,-1,1,-1,1};
    ll y[] = {-1,1,-1,1,-2,-2,2,2};
    ll t,n,m,sr,sc,dr,dc;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>sr>>sc>>dr>>dc;
        struct cell p = cell(sr,sc,0);
        queue<cell> q;
        bool vis[26][26];
        memset(vis,false,sizeof(vis));
        vis[sr][sc]=true;
        q.push(p);
        bool fg=false;
        struct cell f;
        while(!q.empty())
        {
             f = q.front();
            q.pop();
            if(f.r==dr&&f.c==dc)
            {
               fg=true;
                break;
            }
            vis[f.r][f.c]=true;
            for(ll i=0;i<8;i++)
            {
                ll dx = f.r+x[i];
                ll dy = f.c+y[i];
                if(issafe(dx,dy,n,m)&&!vis[dx][dy])
                {
                    q.push(cell(dx,dy,f.dis+1));
                }
            }
        }
        if(fg)
        cout<<f.dis<<endl;
        else
        cout<<-1<<endl;
    }
	//code
	return 0;
}