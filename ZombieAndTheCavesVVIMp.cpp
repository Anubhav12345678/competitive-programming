#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
#include<iterator>
bool isanagram(ll a[],ll b[],ll n)
{
	ll i,j,k;
	map<ll,ll> m1,m2;
	for(i=0;i<n;i++)
	{
		m1[a[i]]++;
		m2[b[i]]++;
	}
	auto it1 = m1.begin();
	auto it2 = m2.begin();
    for(;it1!=m1.end()&&it2!=m2.end();++it1,++it2)
    {
    	if((m2.find(it1->first)==m2.end())||(m1.find(it2->first)==m1.end()))
    	return false;
    	if(it1->second!=it2->second)
    	return false;
    }
    if(it1!=m1.end()||it2!=m2.end())
    return false;
    return true;
	
}
void inc(ll a[],ll l,ll r,ll n)
{
	if(l<0)
	l=0;
	if(r>=n)
	r=n-1;
	a[l]++;
	if(r!=n-1)
	a[r+1]--;
}
void update(ll a[],ll n)
{
	for(ll i=1;i<n;i++)
	a[i]+=a[i-1];
}
int main() {
	ll n,a[100001],i,j,k,t,h[100001];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
		cin>>h[i];
		ll res[n];
		memset(res,0,sizeof(res));
		for(i=0;i<n;i++)
		inc(res,i-a[i],i+a[i],n);
		update(res,n);
		// for(i=0;i<n;i++)
		// cout<<res[i]<<" ";
		if(isanagram(res,h,n))
		cout<<"YES\n";
		else
		cout<<"NO\n";
		
	}
	
	// your code goes here
	return 0;
}