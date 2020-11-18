#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll solve(vector<string> &s,ll h,ll w)
{
	ll i,j,k,l,a,b,c;
	ll dp[h+1][w+1];
	ll phor[h+1][w+1];
	ll pver[h+1][w+1];
	ll pdia[h+1][w+1];
	memset(dp,0,sizeof(dp));
	memset(phor,0,sizeof(phor));
	memset(pver,0,sizeof(pver));
	memset(pdia,0,sizeof(pdia));
	dp[1][1]=1;
	phor[1][1]=1;
	pver[1][1]=1;
	pdia[1][1]=1;
	ll m = 1e9+7;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(i==1&&j==1) continue;
			if(s[i-1][j-1]=='#') continue;
			dp[i][j] = (phor[i][j-1]+pver[i-1][j]+pdia[i-1][j-1])%m;
			phor[i][j] = dp[i][j];
			pver[i][j] = dp[i][j];
			pdia[i][j] = dp[i][j];
			phor[i][j]+= phor[i][j-1];
			pver[i][j]+= pver[i-1][j];
			pdia[i][j]+= pdia[i-1][j-1];
			phor[i][j]%=m;
			pver[i][j]%=m;
			pdia[i][j]%m;
		}
	}
	return dp[h][w]%m;
	
}
int main() {
	
	ll t,n,k,h,w;
	cin>>h>>w;
	vector<string> v(h);
	for(ll i=0;i<h;i++) cin>>v[i];
	cout<<solve(v,h,w);
	
	// your code goes here
	return 0;
}
/*
We have a grid with 
H
 horizontal rows and 
W
 vertical columns of squares. Square 
(
i
,
j
)
, which is at the 
i
-th row from the top and 
j
-th column from the left, is wall if 
S
i
j
 is # and road if 
S
i
j
 is ..

There is a queen, the chess piece, at Square 
(
1
,
1
)
. In one move, it can move any number of squares to the right, downwards, or diagonally to the lower right to a road square without jumping over wall squares.

In how many ways can the queen travel from Square 
(
1
,
1
)
 to Square 
(
H
,
W
)
? Find the count modulo 
(
10
9
+
7
)
.

Here, two ways to travel are considered different if and only if there exists 
i
 such that the position of the queen after the 
i
-th move is different in those two ways.


*/