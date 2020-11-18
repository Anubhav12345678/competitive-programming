#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll solve(string s)
{
	ll n = s.size();
	ll sd[n];
	sd[0] = s[0]-'0';
	ll i,j,k,sum=0;
	for(i=1;i<n;i++)
	{
	sd[i] = (i+1)*(s[i]-'0')+10*sd[i-1];
	sum+=sd[i];
	}
	sum+=sd[0];
	return sum;
	
}
int main() {
	ll t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<solve(s)<<endl;
	}
	// your code goes here
	return 0;
}