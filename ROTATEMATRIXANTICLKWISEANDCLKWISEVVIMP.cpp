#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
// 90deg clkwise
void solve(vector<vector<int>> &v)
{
	int n = v.size();
	int m = v[0].size();
	int i,j,k,l,x,y;
	for(x=0;x<n/2;x++)
	{
		for(y=x;y<n-x-1;y++)
		{
			int tmp = v[x][y];
			v[x][y]=v[n-y-1][x];
			v[n-y-1][x] = v[n-x-1][n-y-1];
			v[n-x-1][n-y-1]=v[y][n-x-1];
			v[n-x-1]=tmp;
		}
	}
}
// 90deg anticlkwise
void solve2(vector<vector<int>> &v)
{
	int n = v.size();
	int m = v[0].size();
	int i,j,k,l,x,y;
	for(x=0;x<n/2;x++)
	{
		for(y=x;y<n-x-1;y++)
		{
			int tmp = v[x][y];
			v[x][y]=v[y][n-x-1];
			v[y][n-x-1]=v[n-x-1][n-y-1];
			v[n-x-1][n-y-1]=v[n-y-1][x];
			v[n-y-1][x]=tmp;
		}
	}
}
int main() {
	// your code goes here
	return 0;
}