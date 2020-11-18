#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
#define ff first
#define se second
/*
Vivek has encountered a problem. He has a maze that can be represented as an n×m grid. Each of the grid cells may represent
 the following:

Empty — '.'
Wall — '#'
Good person  — 'G'
Bad person — 'B'
The only escape from the maze is at cell (n,m).

A person can move to a cell only if it shares a side with their current cell and does not contain a wall. Vivek wants to block
 some of the empty cells by replacing them with walls in such a way, that all the good people are able to escape, while none of
  the bad people are able to. A cell that initially contains 'G' or 'B' cannot be blocked and can be travelled through.

Help him determine if there exists a way to replace some (zero or more) empty cells with walls to satisfy the above conditions.

It is guaranteed that the cell (n,m) is empty. Vivek can also block this cell.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s[51];
ll n,m;
map<pair<ll,ll>,ll > mp;
 
void block(ll x,ll y)
{
	if(x==-1 or y==-1 or x==n or y==m or s[x][y]=='G' or s[x][y]=='B')
	return ;
	s[x][y]='#';
}
 
void dfs(ll x,ll y)
{
	if(x==-1 or y==-1 or x==n or y==m or mp[{x,y}] or s[x][y]=='#') return ;
	mp[{x,y}]=1;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
 
int main()
{
	ll i,j,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='B')
				{
					block(i-1,j);
					block(i,j-1);
					block(i+1,j);
					block(i,j+1);
				}
			}
		}
		mp.clear();
		dfs(n-1,m-1);
		bool fl=true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='G')
				{
					if(!mp[{i,j}]) fl=false;
				}
				else if(s[i][j]=='B')
				{
					if(mp[{i,j}]) fl=false;
				}
			}
		}
		if(fl)
		cout<<"Yes\n";
		else cout<<"No\n";
	}
}