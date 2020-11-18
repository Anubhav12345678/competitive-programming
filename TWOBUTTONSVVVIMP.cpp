
//another bfs
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define MAX 1e7
#define inf INT_MAX
#include<queue>
ll MAX = 1e7;
ll solve(ll n,ll m){
	ll dis[MAX];
	if(n>=m) return n-m;
	memset(dis,-1,sizeof(dis));
	ll src = n;
	dis[src] = 0;
	queue<ll> q;
	q.push(src);
	while(!q.empty()){
		ll u = q.front();
		// cout<<u<<endl;
		q.pop();
		if(u==m)
		return dis[u];
		if((2*u)<1e5){
			if(~dis[2*u]) continue;
			dis[2*u] = dis[u]+1;
			q.push(2*u);
			if((2*u)==m) return dis[2*u];
		}
		
		if(u>0){
			if(~dis[u-1]) continue;
			dis[u-1]=dis[u]+1;
			q.push(u-1);
			if((u-1)==m)
			return dis[u-1];
		}
	}
	return dis[m];
}
int main() {
	ll n,m;
	cin>>n>>m;
	cout<<solve(n,m);
}


//BFS
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,t;
}q[100005];
int i,j,k,l,s,m,n,vis[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	int gt=m-n;
	int l=0,r=1;
	q[1].x=n;
	q[1].t=0;
	vis[n]=1;
	while (l<r)
	{
		int k=q[++l].x;
		if (k==m)
		{
			printf("%d\n",q[l].t);
			return 0;
		}
		if (k<m)
		{
			if (!vis[k*2])
			{
				q[++r].x=k*2;
				vis[k*2]=1;
				q[r].t=q[l].t+1;
			}
			if (!vis[k-1]&&k-1>0)
			{
				q[++r].x=k-1;
				q[r].t=q[l].t+1;
				vis[k-1]=1;
			}
		}
		else
		{
			if (!vis[k-1])
			{
				q[++r].x=k-1;q[r].t=q[l].t+1;
				vis[k-1]=1;
			}
		}
	}
}










#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
/*Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing some 
positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue button, device
 subtracts one from the number on the display. If at some point the number stops being positive, the device breaks down. The display 
 can show arbitrarily large numbers. Initially, the display shows number n.

Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?*/
ll solve(ll n,ll m)
{
	
	if(n==m)
	return 0;
	if(m%2==0&&m>n)
	return 1+solve(n,m/2);
	return 1+solve(n,m+1);
}
int main() {
	ll n,m;
	cin>>n>>m;
	cout<<solve(n,m);
	
	// your code goes here
	return 0;
}