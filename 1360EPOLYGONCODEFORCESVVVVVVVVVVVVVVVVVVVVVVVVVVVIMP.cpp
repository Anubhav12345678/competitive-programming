#include <bits/stdc++.h>
using namespace std;
#define ll long long
// ll a[55][55];
#include<vector>

// bool vis[55][55];
string solve(vector<vector<char>> &a,ll n)
{
	ll i,j,k,l;
	// for(i=0;i<n;i++)
	// {
	// for(j=0;j<n;j++)
	// cout<<"a["<<i<<"]["<<j<<"] = "<<a[i][j]<<" ";
	// cout<<endl;
	// }
	// memset(vis,0,sizeof(vis));
	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=n;j++)
	// 	if((i==n||j==n)&&a[i][j]==1) vis[i][j]=1;
	// }
	for(i=n-2;i>=0;i--)
	{
		for(j=n-2;j>=0;j--)
		{
			if(a[i][j]=='1')
			{
				bool rfg=0,cfg=0;
				for(ll r=i+1;r<=n;r++)
				{
					if(a[r][j]=='1')
					{
						rfg=0;
						break;
					}
					else
					{
						rfg=1;
						break;
					}
				}
				for(ll c=j+1;c<=n;c++)
				{
					if(a[i][c]=='1')
					{
						cfg=0;
						break;
					}
					else
					{
						cfg=1;
						break;
					}
				}
				if(rfg==1&&cfg==1) return "NO";
				
			}
		}
	}
	return "YES";
	
}
int main() {
	ll t,n,i,j,k,l;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<vector<char>> a(n,vector<char>(n));
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		cin>>a[i][j];
		// cout<<a[0][0]<<endl;
		cout<<solve(a,n)<<endl;
	}
	// your code goes here
	return 0;
}

/*
Polygon is not only the best platform for developing problems but also a square matrix with side n, initially filled with the
 character 0.

On the polygon, military training was held. The soldiers placed a cannon above each cell in the first row and a cannon to the
 left of each cell in the first column. Thus, exactly 2n cannons were placed.

Initial polygon for n=4.
Cannons shoot character 1. At any moment of time, no more than one cannon is shooting. 
When a 1 flies out of a cannon, it flies forward (in the direction of the shot) until it 
collides with a polygon border or another 1. After that, it takes the cell in which it was before
 the collision and remains there. Take a look at the examples for better understanding.

More formally:

if a cannon stands in the row i, to the left of the first column, and shoots with a 1, then the 1 starts
 its flight from the cell (i,1) and ends in some cell (i,j);
if a cannon stands in the column j, above the first row, and shoots with a 1, then the 1 starts its flight 
from the cell (1,j) and ends in some cell (i,j).
For example, consider the following sequence of shots:


1. Shoot the cannon in the row 2.                         2. Shoot the cannon in the row 2.                         3. Shoot the cannon in column 3.

You have a report from the military training on your desk. This report is a square matrix with side length n consisting of 0 and 1.
 You wonder if the training actually happened. In other words, is there a sequence of shots such that, after the training,
  you get the given matrix?

Each cannon can make an arbitrary number of shots. Before the training, each cell of the polygon contains 0.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

Each test case starts with a line containing an integer n (1≤n≤50) — the size of the polygon.

This is followed by n lines of length n, consisting of 0 and 1 — the polygon matrix after the training.

The total area of the matrices in all test cases in one test does not exceed 105.


*/