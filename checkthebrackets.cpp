#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<queue>
ll solve(string s)
{
	ll n = s.size();
	if(n==1)
	return 0;
	ll i,j;
	queue<char> q;
	for(i=0;i<n;i++)
	{
		if(s[i]=='{')
		q.push(s[i]);
		else
		{
			if(!q.empty())
			{
				q.pop();
			}
			else
			return 0;
		}
	}
	if(!q.empty())
	return 0;
	else
	return 1;
}
int main() {
	ll t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(solve(s))
		cout<<"Balanced\n";
		else
		cout<<"Unbalanced\n";
	}
	// your code goes here
	return 0;
}