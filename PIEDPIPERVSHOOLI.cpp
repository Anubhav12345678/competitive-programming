#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#include<limits.h>
#define V 9
#define inf INT_MAX
#define mp make_pair
#define ff first
#define ss second
bool lose(ll a,ll b,ll x,ll y,ll z)
{
	ll t1 = (ll)(ceil)((float)(z-a)/x);
	ll t2 = (ll)(ceil)((float)(z-b)/y);
	// cout<<(t1>=t2);
	return t1>=t2;
}
int main()
{
	ll n,a,b,x,y,z,p,q,t,i;
	cin>>t;
	while(t--)
	{
		pq<ll> m;
		cin>>n>>a>>b>>x>>y>>z;
		for(i=0;i<n;i++)
		{
			cin>>p;
			m.push(p);
		}
		ll s=0;
		while(m.top()!=0&&lose(a,b,x,y,z))
		{
			s++;
			a+=m.top();
			p = m.top();
			m.pop();
			m.push(p/2);
		}
	    // cout<<"a = "<<a<<endl;
		if(lose(a,b,x,y,z))
		{
			cout<<"RIP\n";
		}
		else
		{
			cout<<s<<endl;
		}
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}