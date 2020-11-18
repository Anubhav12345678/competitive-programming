#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
// https://ideone.com/OJAhdR
vector<vector<int>> solve(int n)
{
	vector<vector<int>> res(n,vector<int>(n,0));
	int rst=0,cst=0,ren=n-1,cen=n-1,num=1,i,j,k,l;
	while(rst<n&&cst<n)
	{
		for(int i=cst;i<=cen;i++)
		res[rst][i]=num++;
		rst++;
		for(i=rst;i<=ren;i++)
		res[i][cen] = num++;
		cen--;
		if(rst<=ren)
		{
			for(i=cen;i>=cst;i--)
			{
				res[ren][i] = num++;
			}
			ren--;
		}
		if(cst<=cen)
		{
			for(i=ren;i>=rst;i--)
			res[i][cst] = num++;
			cst++;
		}
	}
	return res;
}
int main() {
	int n;
	cin>>n;
	vector<vector<int>> res = solve(n);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
		cout<<endl;
	}
	// your code goes here
	return 0;
}