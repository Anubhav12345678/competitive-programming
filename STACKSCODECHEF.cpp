#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll binsearch(vector<ll> v,ll x)
{
	ll i,j,k,ans=-1,m;
	i=0;
	j=v.size()-1;
	while(i<=j)
	{
		m = (i+j)/2;
		if(v[m]>x)
		{
			ans=m;
			j=m-1;
		}
		else
		i=m+1;
	}
	return ans;
}
int main() {
	ll t,n,a[100005],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++) cin>>a[i];
		vector<ll> v;
		v.push_back(a[0]);
		for(i=1;i<n;i++)
		{
			auto x = upper_bound(v.begin(),v.end(),a[i]);
			if(x==v.end())
			v.push_back(a[i]);
			else
			v[(x-v.begin())]=a[i];
		}
		cout<<v.size()<<" ";
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl;
	}
	
	// your code goes here
	return 0;
}