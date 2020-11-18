#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
#include<set>
#include<iterator>
ll gcd(ll a,ll b)
{
	if(a>=b)
	{
		if(b==0)
		return a;
		return gcd(b,a%b);
	}
	else
	{
		if(a==0)
		return b;
		return gcd(a,b%a);
	}
}
// ll gcdofar(ll a[],ll n)
// {
//     if(n==0)
//     return 0;
// 	if(n==1)
// 	return a[0];
// 	ll res=0,i;
// 	for(i=0;i<n;i++)
// 	res = gcd(res,a[i]);
// 	return res;
// }
// ll getmaxin(ll a[],ll n)
// {
// 	ll i,maxi = a[0],res=0;
// 	for(i=1;i<n;i++)
// 	if(a[i]>maxi)
// 	{
// 		maxi = a[i];
// 		res=i;
// 	}
// 	return res;
// }
int main() {
	ll t,n,i,j,temp,u,num;
	cin>>t;
	while(t--)
	{
		set<ll> s;
	set<ll>::iterator it;
	set<ll>::reverse_iterator rit;
	set<ll>::reverse_iterator ritn;
		ll res1=0,res2=0;
		// s.clear();
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>num;
			s.insert(num);
		}
		if(s.size()==1)
		{
			cout<<2*(*s.begin())<<endl;
			continue;
		}
		rit = s.rbegin();
		ll x = *rit;
		// cout<<x<<endl;
		s.erase(*rit);
		for(it = s.begin();it!=s.end();++it)
		{
		res1 = gcd(res1,*it);
		// cout<<*it<<" "<<res1<<endl;
		}
		// cout<<res1<<endl;
		res1+=x;
		// cout<<"res1 = "<<res1<<endl;
		ritn = s.rbegin();
		ll y = *ritn;
		// cout<<y<<endl;
		s.erase(*ritn);
		s.insert(x);
		for(it = s.begin();it!=s.end();++it)
		{
		res2 = gcd(res2,*it);
		// cout<<*it<<" "<<res2<<endl;
		}
		res2+=y;
		// cout<<res2<<endl;
		cout<<max(res1,res2)<<endl;
		s.clear();
		
		
		
		
	}
	
	// your code goes here
	return 0;
}