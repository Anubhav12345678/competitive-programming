#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*
You are given a matrix with n rows (numbered from 1 to n) and m columns (numbered from 1 to m). A number ai,j is written
 in the cell belonging to the i-th row and the j-th column, each number is either 0 or 1.

A chip is initially in the cell (1,1), and it will be moved to the cell (n,m). During each move, it either moves to the 
next cell in the current row, or in the current column (if the current cell is (x,y), then after the move it can be either
 (x+1,y) or (x,y+1)). The chip cannot leave the matrix.

Consider each path of the chip from (1,1) to (n,m). A path is called palindromic if the number in the first cell is equal 
to the number in the last cell, the number in the second cell is equal to the number in the second-to-last cell, and so on.

Your goal is to change the values in the minimum number of cells so that every path is palindromic.

*/
int main() {
	ll i,j,k,l,n,t,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll a[n][m];
		for(i=0;i<n;i++)
		for(j=0;j<m;j++) cin>>a[i][j];
		vector<vector<ll>> v(n+m+1);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
		    {
		    	ll x = i+j;
		    	ll y = (n-i-1)+(m-j-1);
		    	if(x!=y)
		    	v[min(x,y)].push_back(a[i][j]);
		    }
		}
		
		ll ans=0;
	     ll z=0,o=0;
	     for(i=0;i<n+m+1;i++){
	     	z=o=0;
	     	for(j=0;j<v[i].size();j++){
	     		if(v[i][j]==0) z++;
	     		else
	     		o++;
	     	}
	     	ans+=min(o,z);
	     }
	     
	     cout<<ans<<endl;
	}
	
	// your code goes here
	return 0;
}