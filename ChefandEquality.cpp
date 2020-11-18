#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
int main() {
	ll n,t,a[100005],i,j,k,s=0;
	cin>>t;
	while(t--)
	{
		map<ll,ll> m;
		s=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
	    cin>>a[i];
	    m[a[i]]++;
		}
		ll mini = -1,maxele;
		for(auto x:m)
		{
			if(x.second>mini)
			{
			mini=x.second;
			maxele = x.first;
			}
		}
		for(i=0;i<n;i++)
		if(a[i]!=maxele)
		s++;
		cout<<s<<endl;
	}
	// your code goes here
	return 0;
}