#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
/*
Let's define the following recurrence:
an+1=an+minDigit(an)⋅maxDigit(an).
Here minDigit(x) and maxDigit(x) are the minimal and maximal digits in the decimal representation of x without
 leading zeroes. For examples refer to notes.

Your task is calculate aK for given a1 and K.


*/
ll mindig(string s)
{
	ll ans=INT_MAX;
	for(ll i=0;i<s.size();i++)
	ans = min(ans,(ll)(s[i]-'0'));
	return ans;
}

ll maxdig(string s)
{
	ll ans=INT_MIN;
	for(ll i=0;i<s.size();i++)
	ans = max(ans,(ll)(s[i]-'0'));
	return ans;
}
ll solve(ll a1,ll k)
{
	ll i,j,l,n,m;
	vector<ll> res;
	res.push_back(a1);
	while(res.size()<k)
	{
		ll mini = mindig(to_string(res.back()));
		ll maxi = maxdig(to_string(res.back()));
		res.push_back(res.back()+mini*maxi);
		if(mini==0)
		break;
	}
	if(res.size()<=k)
	return res.back();
	else
	return res[k-1];
	
}
int main() {
	
	ll a1,t,k;
	cin>>t;
	while(t--)
	{
		cin>>a1>>k;
		cout<<solve(a1,k)<<endl;
	}
	
	// your code goes here
	return 0;
}