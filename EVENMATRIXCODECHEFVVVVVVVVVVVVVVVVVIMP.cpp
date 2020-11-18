#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
Chef has an integer N and he wants to generate a matrix M with N rows (numbered 1 through N) and
 N columns (numbered 1 through N). He thinks that M would be delicious if:

Each element of this matrix is an integer between 1 and N2 inclusive.
All the elements of the matrix are pairwise distinct.
For each square submatrix containing cells in rows r through r+a and in columns c through c+a
 (inclusive) for some valid integers r, c and a≥0:
Mr,c+Mr+a,c+a is even
Mr,c+a+Mr+a,c is even
Can you help Chef generate a delicious matrix? It can be proved that a solution always exists.
 If there are multiple solutions, you may find any one.





*/
void solve(ll n)
{
	ll i,j,k,l,m;
	vector<vector<ll>> v(n,vector<ll>(n,-1));
	for(i=1;i<=n;i++)
	{
		v[i-1][0]=i*i;
		ll num= i*i;
		for(j=2;j<=i;j++)
		v[i-1][j-1] = --num;
	}
	for(i=n;i>1;i--)
	{
		ll num = v[i-1][i-1];
		for(j=i-1;j>0;j--)
		v[j-1][i-1]=--num;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<v[i][j]<<" ";
		cout<<endl;
	}
}
int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		solve(n);
	}
	// your code goes here
	return 0;
}