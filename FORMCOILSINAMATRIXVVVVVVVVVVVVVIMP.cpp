#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

Form coils in a matrix
Given a positive integer n that represents dimensions of a 4n x 4n matrix with values from 1 to n filled from 
left to right and top to bottom. Form two coils from matrix and print the coils.

Examples:

Input  : n = 1;
Output : Coil 1 : 10 6 2 3 4 8 12 16 
         Coil 2 : 7 11 15 14 13 9 5 1
Explanation : Matrix is 
1  2  3  4 
5  6  7  8 
9  10 11 12 
13 14 15 16

*/
#include<vector>
void solve(ll n)
{
	// 4n*4n matrix with ele from 1 to 4n*4n
	ll m = 8*n*n;
	ll coil1[m];
	ll coil2[m];
	ll cur = coil1[0] = 4*n*2*n+2*n;
	ll  ind = 1,step=2,fg=1;
	while(ind<m)
	{
		for(ll i=0;i<step;i++)
		{
		 cur = coil1[ind++] = cur-4*n*fg;
		 if(ind>=m) break;
		}
		if(ind>=m) break;
		
		for(ll i=0;i<step;i++)
		{
			cur = coil1[ind++] = cur+fg;
		 if(ind>=m) break;
		}
		step+=2;
		fg*=-1;
	}
	
	for(ll i=0;i<m;i++)
	coil2[i] = 16*n*n+1-coil1[i];
	
	for(ll i=0;i<m;i++) cout<<coil1[i]<<" ";
	cout<<endl;
	for(ll i=0;i<m;i++) cout<<coil1[i]<<" ";
}
int main() {
	
	ll n;
	cin>>n;
	solve(n);
	// your code goes here
	return 0;
}