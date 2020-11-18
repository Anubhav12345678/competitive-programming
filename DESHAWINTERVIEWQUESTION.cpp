#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll solve(string s)
{
	ll n=s.size(),i=0,j=0,k=0,f=0;
	while(i<n&&s[i]=='1')
	i++;
	if(i==n)
	return 0;
	else
	{
		ll ans=0;
		bool flag=false;
		for(j=i;j<n;j++)
		{
			k=j;
			while(j<n&&s[j]=='1')
			{
			j++;
			flag=true;
			}
			// cout<<"j = "<<j<<endl;
			if(k!=j)
			{
			ans+=2;
			j--;
			}
			if(j>=n)
			return ans;
		}
		if(j<n&&s[n-1]=='0')
		ans+=1;
		if(!flag)
		{
			ans+=1;
			return ans;
		}
		return ans;
	}
	
}
int main() {
	string s;
	cin>>s;
	cout<<solve(s)<<endl;
	// your code goes here
	return 0;
}