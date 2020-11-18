#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
int main() {
	char s[101];
	ll t,n,i,j,x,p;
	cin>>t;
	while(t--)
	{
		x=0;
		cin>>s;
		n = strlen(s);
		for(i=0;i<n;i++)
		x+=s[i]-'0';
		if(x%10==0)
		{
		s[n]='0';
		n++;
		}
		else
		{
			p = ((x/10)+1)*10-x;
			s[n] = (char)(p+48);
			n++;
		}
		for(i=0;i<n;i++)
		cout<<s[i];
		cout<<endl;
	}
	// your code goes here
	return 0;
}