#include <bits/stdc++.h>
using namespace std;
#define ll long long
//https://ideone.com/eZAFXB
ll solveutil(string s,ll l,ll h,ll n)
{
	if(s[l]!=s[h])
	return 0;
	ll cnt=2;
	while(l>=0&&h<n&&s[l]==s[h])
	{
		if(l>1&&h<n-1&&s[l]!=s[l-1]&&s[h]!=s[h+1])
		{
			cnt+=2;
			l--;
			h++;
		}
		else
		break;
	}
	return cnt;
}
ll solve(string s)
{
	ll i,j,k,l;
	ll n = s.size();
	ll ans=0;
	for(i=0;i<n-1;i++)
	{
		ll val = solveutil(s,i,i+1,n);
		ans = max(ans,val);
	}
	return ans;
}
int main() {
	string s;
	cin>>s;
	cout<<solve(s);
	// your code goes here
	return 0;
}