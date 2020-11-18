#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
// Make r combinations out of n things
void solve(vector<vector<int>> &res,vector<int> &v,int st,int k,int n)
{
	if(k==0)
	{
		res.push_back(v);
		return;
	}
	for(int i=st;i<=n;i++)
	{
		v.push_back(i);
		solve(res,v,i+1,k-1,n);
		v.pop_back();
	}
	return;
}
int main() {
	vector<vector<int>> res;
	vector<int> v;
	int n,k,i,j;
	cin>>n>>k;
	solve(res,v,1,k,n);
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
		cout<<endl;
	}
	// your code goes here
	return 0;
}