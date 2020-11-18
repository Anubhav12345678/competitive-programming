#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<string.h>
#define MAX 5
#define pob pop_back
bool issafe(int m[MAX][MAX],int n,int row,int col,bool vis[][MAX])
{
	if(row==-1||col==-1||row>=n||col>=n||vis[row][col]||m[row][col]==0)
	return false;
	return true;
}
void solve(int row,int col,int m[MAX][MAX],int n,bool vis[][MAX],string &path,vector<string> &res)
{
	if(row==-1||col==-1||row>=n||col>=n||vis[row][col]||m[row][col]==0)
	return;
	if(row==n-1&&col==n-1)
	{
		res.pb(path);
		return;
	}
	vis[row][col]=true;
	if(issafe(m,n,row+1,col,vis))
	{
		path.pb('D');
		solve(row+1,col,m,n,vis,path,res);
		path.pob();
	}
	if(issafe(m,n,row,col+1,vis))
	{
		path.pb('R');
		solve(row,col+1,m,n,vis,path,res);
		path.pob();
	}
	if(issafe(m,n,row-1,col,vis))
	{
		path.pb('U');
		solve(row-1,col,m,n,vis,path,res);
		path.pob();
	}
	if(issafe(m,n,row,col-1,vis))
	{
		path.pb('L');
		solve(row,col-1,m,n,vis,path,res);
		path.pob();
	}
	vis[row][col]=false;
}
void printpaths(int m[MAX][MAX],int n)
{
	vector<string> res;
	string path;
	bool vis[MAX][MAX];
	memset(vis,false,sizeof(vis));
	solve(0,0,m,n,vis,path,res);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
}
int main() {
	int m[MAX][MAX] = { { 1, 0, 0, 0, 0 }, 
                        { 1, 1, 1, 1, 1 }, 
                        { 1, 1, 1, 0, 1 }, 
                        { 0, 0, 0, 0, 1 }, 
                        { 0, 0, 0, 0, 1 } }; 
    int n = sizeof(m) / sizeof(m[0]); 
    printpaths(m, n); 
  
    return 0; 
	// your code goes here
	return 0;
}