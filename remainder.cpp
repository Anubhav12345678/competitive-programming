#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
int main() {
	string s;
	ll n,x,y,i,j,cnt=0;
	cin>>n>>x>>y;
	cin>>s;
	// cout<<s<<endl;
	reverse(s.begin(),s.end());
	// cout<<s<<endl;
	for(i=0;i<x;i++)
	{
		if(s[i]=='1')
		{
			if(i!=y)
			cnt++;
		}
		else if(i==y&&s[i]=='0')
		cnt++;
		// cout<<i<<" "<<cnt<<endl;
	}
	if(s[i]!='1')
	cnt++;
		cout<<cnt<<endl;
	return 0;
}