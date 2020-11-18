#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include<vector>
#include<map>
/*no of subarrays hvng prod=p^2-q^2 p and q areint */
ll solve(vector<ll> &v,ll s)
{
	ll i,j,k,l,n=v.size();
	map<ll,ll> mp;
	ll sum=0LL,ans=0LL;
	for(i=0;i<n;i++)
	{
		sum+=v[i];
		if(sum==s)
		ans++;
		if(mp.find(sum-s)!=mp.end())
		ans+=mp[sum-s];
		mp[sum]++;
	}
	return ans;
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]%4==0)
			v[i]=2;
			else if(v[i]%2==0)
			v[i]=1;
			else
			v[i]=0;
		}
		ll tot = (n*(n+1))/2;
		cout<<tot-solve(v,1)<<endl;
 	}
	// your code goes here
	return 0;
}