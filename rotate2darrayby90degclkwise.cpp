class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,k,l,n=matrix.size(),m=matrix[0].size();
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int c = matrix[i][j];
                matrix[i][j] =matrix[j][i];
                matrix[j][i] = c;
                // cout<<"matrix["<<i<<"]["<<j<<"]= "<<matrix[i][j]<<endl;
            }
        }
        
        for(i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
//easiest









#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 10001
void solve(ll a[][max],ll n)
{
	ll x,i,j,y;
	for(x = 0;x<n/2;x++)
	{
		for(y=x;y<n-x-1;y++)
		{
			ll tmp = a[x][y];
			a[x][y] = a[n-y-1][x];
			a[n-y-1][x] = a[n-x-1][n-y-1];
			a[n-x-1][n-y-1] = a[y][n-x-1];
			a[y][n-x-1] = tmp;
		}
	}
}
int main() {
	ll t,a[10001][10001],i,j,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		cin>>a[i][j];
		solve(a,n);
		for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		// cout<<endl;
		}
	}
	// your code goes here
	return 0;
}
//me............................................................
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
int minjumps(vector<int> &v)
{
	int i,j,k,l,n=v.size();
	int step=0,reach=0,lastreach=0;
	for(i=0;i<n;i++)
	{
		if(i>lastreach)
		{
			lastreach=reach;
			step++;
		}
		reach = max(reach,i+v[i]);
	}
	if(lastreach<n-1)
	return 0;
	return step;
}
int main() {
	int n,i,j,k,l;
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	cout<<minjumps(v);
	// your code goes here
	return 0;
}