#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<iterator>
#include<utility>
#define pb push_back
#define mp make_pair
#define f first
#define s second
int main() {
	vector<pair<char, ll>> v1;
	vector<pair<char, ll>> v2;
	string s1,s2;
     ll t,i,j,p,q,len1,len2;
     cin>>t;
     while(t--)
     {
     	v1.clear();
     	v2.clear();
     	cin>>s1>>s2;
     	len1 = s1.size();
     	len2 = s2.size();
     	v1.pb(mp(s1[0],1));
     	for(i=1;i<len1;i++)
     	{
     		if(s1[i]==v1.back().f)
     		++v1.back().s;
     		else
     		v1.pb(mp(s1[i],1));
     	}
     	v2.pb(mp(s2[0],1));
     	for(i=1;i<len2;i++)
     	{
     		if(s2[i]==v2.back().f)
     		++v2.back().s;
     		else
     		v2.pb(mp(s2[i],1));
     	}
     	// cout<<"sjdfhksdjfh\n";
     	if(v1.size()!=v2.size())
     	{
     		cout<<"NO\n";
     		continue;
     	}
     	else
     	{
     		ll a = v1.size();
     		for(i=0;i<a;i++)
     		if((v1[i].f!=v2[i].f)||v1[i].s>v2[i].s)
     		break;
     		if(i==a)
     		cout<<"YES\n";
     		else
     		cout<<"NO\n";
     	}
     }
	
	// your code goes here
	return 0;
}