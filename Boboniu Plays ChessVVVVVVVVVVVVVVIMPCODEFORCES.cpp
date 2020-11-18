#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
#define ff first
#define se second
/*
Boboniu likes playing chess with his employees. As we know, no employee can beat the boss in the chess game, 
so Boboniu has never lost in any round.

You are a new applicant for his company. Boboniu will test you with the following chess question:

Consider a n×m grid (rows are numbered from 1 to n, and columns are numbered from 1 to m). You have a chess piece,
 and it stands at some cell (Sx,Sy) which is not on the border (i.e. 2≤Sx≤n−1 and 2≤Sy≤m−1).

From the cell (x,y), you can move your chess piece to (x,y′) (1≤y′≤m,y′≠y) or (x′,y) (1≤x′≤n,x′≠x). In other words, 
the chess piece moves as a rook. From the cell, you can move to any cell on the same row or column.

Your goal is to visit each cell exactly once. Can you find a solution?

Note that cells on the path between two adjacent cells in your route are not counted as visited, and it is not required
 to return to the starting point.

Input
The only line of the input contains four integers n, m, Sx and Sy (3≤n,m≤100, 2≤Sx≤n−1, 2≤Sy≤m−1) — the number of rows, 
the number of columns, and the initial position of your chess piece, respectively.

*/
ll isval(ll i,ll j,ll n,ll m){
	return i>=1&&j>=1&&i<=n&&j<=m;
}
void solve(ll n,ll m,ll sx,ll sy){
	ll i,j,k,l,a,b;
	cout<<sx<<" "<<sy<<endl;
	for(i=1;i<=n;i++)
	if(i!=sx)cout<<i<<" "<<sy<<endl;
	
	ll dir=0;
	for(i=1;i<=m;i++){
		if(i==sy) continue;
		if(dir==0){
			cout<<n<<" "<<i<<endl;
			for(j=n-1;j>=1;j--)
			cout<<j<<" "<<i<<endl;
			dir=1;
		}
		else{
			cout<<1<<" "<<i<<endl;
			for(j=2;j<=n;j++)
			cout<<j<<" "<<i<<endl;
			dir=0;
		}
	}
}
int main() {
	ll n,m,sx,sy;
	cin>>n>>m>>sx>>sy;
	solve(n,m,sx,sy);
	// your code goes here
	return 0;
}