#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
bool solve(string s)
{
	ll n=s.size(),i,j,k,l;
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
			if(s[i]=='1')
			return true;
			else
			return false;
		}
		while(i<n&&s[i]!='1')
		i++;
		if(i==n)
		return false;
		s[i]='x';
		if(i+1<n)
		{
			if(s[i+1]=='1')
			s[i+1]='0';
			else
			s[i+1]='1';
		}
		else
		{
			return true;
		}
	}
	return false;
	
}
int main() {
	ll t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(solve(s))
		cout<<"WIN\n";
		else
		cout<<"LOSE\n";
	}
	// your code goes here
	return 0;
}