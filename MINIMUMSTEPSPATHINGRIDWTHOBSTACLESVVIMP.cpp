#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
struct p
{
	int x,y,dis;
};
bool isval(int n,int m,int x,int y,bool vis[][10001],vector<vector<int>> g)
{
	if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&g[x][y]!=1) return 1;
	return 0;
}

int solve(vector<vector<int>> g,int sr,int sc,int dc,int dr)
{
  int dx[]	={-1,1,0,0};
  int dy[] = {0,0,-1,1};
  int n= g.size();
  int m = g[0].size();
  int i,j,k,l;
  queue<p> q;
  //if(g[0][])
  q.push({sr,sc,0});
  bool vis[10001][10001];
  memset(vis,0,sizeof(vis));
  vis[sr][sc]=1;
  while(!q.empty())
  {
  	struct p t = q.front();
  	q.pop();
  	if(t.x==dr&&t.y==dc) return t.dis;
  	
  	for(i=0;i<4;i++)
  	{
  		int nx=t.x+dx[i];
  		int ny = t.y+dy[i];
  		if(isval(n,m,nx,ny,vis,g))
  		{
  			vis[nx][ny]=1;
  			q.push({nx,ny,t.dis+1});
  		}
  	}
  	// return INT_MAX;
  	
  }
  return INT_MAX;
}
int main() {
	int n,m,i_x,i_y,d_x,d_y;
	cin>>n>>m>>i_x>>i_y>>d_x>>d_y;
	vector<vector<int>> vec(n,vector<int>(n));
	int i,j;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  cin>>vec[i][j];
    int y=solve(vec,i_x,i_y,d_y,d_x);
    cout<<y;
}