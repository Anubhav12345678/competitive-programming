#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
#include<limits.h>
struct node
{
    ll ind,dis;
    node(ll a,ll b)
    {
        ind = a;
        dis = b;
    }
};
ll solve(ll a[],ll n)
{
  queue<node> q;
  ll i,j,k,l,ind;
  q.push(node(0,0));
  ll steps=-1;
  bool vis[n];
  memset(vis,false,sizeof(vis));
  vis[0]=true;
  ll step=-1;
  while(!q.empty())
  {
     struct node x = q.front();
     q.pop();
     ll ind = x.ind;
     ll dis = x.dis;
     if(ind==n-1)
     {
         steps=dis;
         break;
     }
     i = a[ind];
     for(j=1;j<=i;j++)
     {
         if(n>ind+j&&!vis[ind+j])
         {
             q.push(node(ind+j,dis+1));
             vis[ind+j]=true;
         }
     }
     
  }
  return steps;
  
}
ll a[10000001];
int main() {
    ll t,n,i,j,k;
    cin>>t;
    while(t--)
    {
       cin>>n;
       for(i=0;i<n;i++)
       cin>>a[i];
       cout<<solve(a,n)<<endl;
    }
	//code
	return 0;
}