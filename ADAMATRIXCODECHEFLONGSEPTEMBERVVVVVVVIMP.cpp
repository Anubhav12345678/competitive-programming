#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#include<vector>
int main() {
	ll i,j,k,l,n,m,cnt,t;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) cin>>a[i][j];
		}
		
		vector<ll> p;
		for(i=0;i<n;i++)
		{
		  if(a[0][i]!=(i+1)) p.pb(1);
		  else
		  p.pb(0);
		}
		
		ll tot=0;
		for(j=n-1;j>0;j--){
			if(p[j]==1){
				tot++;
				for(i=j;i>0;i--)
				p[i]^=1;
			}
		}
		cout<<tot<<endl;
	}
	
	// your code goes here
	return 0;
}
/*
Chef Ada has a matrix with N rows (numbered 1 through N from top to bottom) and N columns (numbered 1 through N from left to right) 
containing all integers between 1 and N2 inclusive. For each valid i and j, let's denote the cell in the i-th row and j-th column
 by (i,j).

Ada wants to sort the matrix in row-major order ― for each valid i and j, she wants the cell (i,j) to contain the value (i−1)⋅N+j.

In one operation, Ada should choose an integer L and transpose the submatrix between rows 1 and L and columns 1 and L
 (inclusive). Formally, for each i and j (1≤i,j≤L), the value in the cell (i,j) after this operation is equal to the
  value in (j,i) before it.

The initial state of the matrix is chosen in such a way that it is possible to sort it using a finite number of 
operations (possibly zero). Find the smallest number of operations required to sort the matrix.



*/