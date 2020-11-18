#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<map>
#include<iterator>
int main() {
	ll n,i,j,k,t,l,h;
	string s2,s,res;
	map<string,ll> m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s;
		m[s] =1;
		}
		cin>>s2;
		l = 0;
		h=0;
		ll len = s2.size();
		while(l<len&&h<len)
		{
			res = s2.substr(l,h-l+1);
			if(m.find(res)!=m.end())
			l=h+1;
			else
			h++;
		}
		if(l==h+1)
		cout<<1<<endl;
		else
		cout<<0<<endl;
	}
	// your code goes here
	return 0;
} 	