#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
int binsearch(vector<int> &v,int x)
{
	// if(l>h)
	// return -1;
	int i,j,k,l,m,n=v.size(),ans;
	i=0,j=n-1,ans=-1;
	while(i<=j)
	{
		int m = i+(j-i)/2;
		if(v[m]<=x)
		{
			// ans=m;
			i=m+1;
		}
		else
		{
			ans=m;
		j=m-1;
		}
		
	}
	return ans;
}
int solve(vector<int> &v)
{
	int i,j,k,l,m,n=v.size();
	vector<int> res;
	res.pb(v[0]);
	for(i=1;i<n;i++)
	{
		if(v[i]>res[res.size()-1])
		res.pb(v[i]);
		else
		{
			int p = binsearch(res,v[i]);
			res[res.size()-1]=v[i];
		}
	}
	return res.size();
	
}
int main() {
	vector<int> v = {3,1,5,2,6,4,9};
	cout<<solve(v)<<endl;
	// your code goes here
	return 0;
}