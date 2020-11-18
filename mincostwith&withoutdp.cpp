#include <bits/stdc++.h>
using namespace std;
#include<limits.h>
#define ll long long
// min cost to go from cell 00 to cell mn without dp
ll min(ll a,ll b,ll c)
{
	ll m;
	m = (a<b)?a:b;
	if(m>c)
	m=c;
	return m;
}
#define MAX 1001
ll solve(ll m,ll n,ll a[MAX][MAX])
{
	if(m<0||n<0)
	return INT_MAX;
	if(m==0&&n==0)
	return a[m][n];
	return a[m-1][n-1]+min(solve(m-1,n,a),solve(m,n-1,a),solve(m-1,n-1,a));
}
int main() {
	ll i,j,a[1001][1001],n,m;
	cin>>m>>n;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	cout<<solve(m,n,a)<<endl;
	
	// your code goes here
	return 0;
}
// using dp
/*
#include<stdio.h> 
#include<limits.h> 
#define R 3 
#define C 3 

int min(int x, int y, int z); 

int minCost(int cost[R][C], int m, int n) 
{ 
	int i, j; 

	// Instead of following line, we can use int tc[m+1][n+1] or 
	// dynamically allocate memory to save space. The following line is 
	// used to keep the program simple and make it working on all compilers. 
	int tc[R][C]; 

	tc[0][0] = cost[0][0]; 

	// Initialize first column of total cost(tc) array 
	for (i = 1; i <= m; i++) 
		tc[i][0] = tc[i-1][0] + cost[i][0]; 

	// Initialize first row of tc array 
	for (j = 1; j <= n; j++) 
		tc[0][j] = tc[0][j-1] + cost[0][j]; 

	// Construct rest of the tc array 
	for (i = 1; i <= m; i++) 
		for (j = 1; j <= n; j++) 
			tc[i][j] = min(tc[i-1][j-1], 
						tc[i-1][j], 
						tc[i][j-1]) + cost[i][j]; 

	return tc[m][n]; 
} 

 A utility function that returns minimum of 3 integers 
int min(int x, int y, int z) 
{ 
if (x < y) 
	return (x < z)? x : z; 
else
	return (y < z)? y : z; 
} 

// Driver program to test above functions 
int main() 
{ 
int cost[R][C] = { {1, 2, 3}, 
					{4, 8, 2}, 
					{1, 5, 3} }; 
printf(" %d ", minCost(cost, 2, 2)); 
return 0; 
} 



*/