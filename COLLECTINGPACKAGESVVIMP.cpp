#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
bool comp(vector<ll> a,vector<ll> b)
{
	ll x1 = a[0],x2 = b[0],y1 = a[1],y2 = b[1];
	if(x1!=x2)
	return x1<x2;
	return y1<y2;
}
void solve(vector<vector<ll>> &v)
{
	ll n = v.size();
	ll i,j,k,l,r;
	sort(v.begin(),v.end(),comp);
	string res="";
	for(i=0;i<n-1;i++)
	{
		if(v[i+1][0]>=v[i][0]&&v[i+1][1]>=v[i][1])
		continue;
		else
		break;
	}
	if(i!=n-1)
	{
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	l = v[0][0];
	r = v[0][1];
	while(l--)
	res.push_back('R');
	while(r--)
	res.pb('U');
	for(i=1;i<n;i++)
	{
		l  =v[i][0]-v[i-1][0];
		r = v[i][1]-v[i-1][1];
		while(l--)
	res.push_back('R');
	while(r--)
	res.pb('U');
	}
	cout<<res<<endl;
	
}
int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<vector<ll>> v(n,vector<ll>(2));
		for(ll i=0;i<n;i++)
		{
			cin>>v[i][0]>>v[i][1];
		}
		solve(v);
	}
	// your code goes here
	return 0;
}