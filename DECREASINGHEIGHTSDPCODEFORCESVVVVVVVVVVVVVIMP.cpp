/*
You are playing one famous sandbox game with the three-dimensional world. The map of the world can be represented as a matrix 
of size n×m, where the height of the cell (i,j) is ai,j.

You are in the cell (1,1) right now and want to get in the cell (n,m). You can move only down (from the cell (i,j) to the cell (i+1,j))
 or right (from the cell (i,j) to the cell (i,j+1)). There is an additional restriction: if the height of the current cell is x then
  you can move only to the cell with height x+1.

Before the first move you can perform several operations. During one operation, you can decrease the height of any cell by one. I.e.
 you choose some cell (i,j) and assign (set) ai,j:=ai,j−1. Note that you can make heights less than or equal to zero. Also note that
  you can decrease the height of the cell (1,1).

Your task is to find the minimum number of operations you have to perform to obtain at least one suitable path from the cell (1,1) to 
the cell (n,m). It is guaranteed that the answer exists.

You have to answer t independent test cases.


*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[102][102],dp[102][102];
ll n,m;
ll solveutil(ll i,ll j,ll val)
{
	// val uss i,j point pe desired value hai
	if(i==n-1&&j==m-1)
	{
		if(a[i][j]<val) return 1e18;
		else return a[i][j]-val;
	}
	if(i>=n||j>=m) return 1e18;
	if(a[i][j]<val) return 1e18;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ch = a[i][j]-val;
	return dp[i][j]=ch+min(solveutil(i,j+1,val+1),solveutil(i+1,j,val+1));
}
ll solve()
{
	ll i,j,k,l;
	ll ans=1e18;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			memset(dp,-1,sizeof(dp));
			ll firstval = a[i][j]-(i+j); // fixing the val at a[i][j] and finding the min path value; 
			ans= min(ans,solveutil(0,0,firstval));
		}
	}
	return ans;
}
int main() {
	ll t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		cin>>a[i][j];
		cout<<solve()<<endl;
	}
	// your code goes here
	return 0;
}