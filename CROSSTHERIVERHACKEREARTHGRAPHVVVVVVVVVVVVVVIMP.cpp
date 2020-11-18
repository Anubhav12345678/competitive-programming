#include<bits/stdc++.h>
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define sfd(n) scanf("%d",&n)
#define MAXX 1000000000
#define MINX -1000000000
using namespace std;
/*
You are required to cross a river to reach your destination. The streamflow of the river was fast, therefore, you cannot cross
 the river by swimming. 

The river is available at the X-axis and its boundary is marked by Y coordinates, from  to .  

--------------------------------------------------------------------------------- 

..................................................................................................

..................................................................................................

..................................................................................................

---------------------------------------------------------------------------------- 

You are provided with some rocks along with their centers and radius respectively. Currently, you are standing on the shore .
 You cannot jump between rocks but can move from one rock to another if both rocks overlap at some point. You are required to
  determine whether you will be able to cross the river by using rocks or not. If you can cross the river, then print the minimum
   number of rocks that are required to cross the river. Otherwise, print .



*/
pair<pair<int,int>,int> pt[5005];
vector<int> adj[5005];
int s,d;
int up[5005],down[5005];
queue<int> q;
bool Intersects(int x1,int y1,int r1,int x2,int y2,int r2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1+r2)*(r1+r2);
}
void bfs(int arr[])
{
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        int a=pt[k].fi.fi;
        int b=pt[k].fi.se;
        for(int j=0;j<adj[k].size();j++)
        {
            if(arr[adj[k][j]]>arr[k]+1)
            {
                arr[adj[k][j]]=arr[k]+1;
                q.push(adj[k][j]);
            }
        }
    }
}
int main()
{
    int t;
    sfd(t);
    assert(1<=t&&t<=10);
    while(t--)
    {
        int n;
        sfd(n);
        assert(1<=n&&n<=5000);
        for(int i=0;i<n;i++)
        {
            int x,y,r;
            sfd(x);
            sfd(y);
            sfd(r);
            assert(MINX<=x&&x<=MAXX);
            assert(MINX<=y&&y<=MAXX);
            assert(1<=r&&r<=MAXX);
            pt[i]=mkp(mkp(x,y),r);
        }
        sfd(s);
        sfd(d);
        assert(MINX<=s&&s<=MAXX);
        assert(MINX<=d&&d<=MAXX);
        assert(s>=d);
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            up[i]=INT_MAX;
            down[i]=INT_MAX;
        }
        for(int i=0;i<(n-1);i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(Intersects(pt[i].fi.fi,pt[i].fi.se,pt[i].se,pt[j].fi.fi,pt[j].fi.se,pt[j].se))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(pt[i].fi.se-pt[i].se<=d)
            {
                up[i]=1;
                q.push(i);
            }
        }
        bfs(up);
        for(int i=0;i<n;i++)
        {
            if(pt[i].fi.se+pt[i].se>=s)
            {
                down[i]=1;
                q.push(i);
            }
        }
        bfs(down);
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(up[i]!=INT_MAX && down[i]!=INT_MAX)
                ans=min(ans,up[i]+down[i]-1);
        }
        if(ans==INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
}