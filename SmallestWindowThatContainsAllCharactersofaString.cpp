#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://ideone.com/CzqGN8
ll solve(string s)
{
	bool vis[256];
	
	memset(vis,false,sizeof(vis));
	ll i,j,k,l,n=s.size();
	ll distcnt=0;
	for(i=0;i<n;i++)
	{
		if(!vis[s[i]])
		{
			vis[s[i]]=true;
			distcnt++;
		}
	}
	ll st=0,stind=-1,minlen=n,cnt=0,curcnt[256];
	memset(curcnt,0,sizeof(curcnt));
	for(i=0;i<n;i++)
	{
		curcnt[s[i]]++;
		if(curcnt[s[i]]==1)
		cnt++;
		if(cnt==distcnt)
		{
			while(curcnt[s[st]]>1)
			{
				if(curcnt[s[st]]>1)
				curcnt[s[st]]--;
				st++;
			}
			ll len = i-st+1;
			if(len<minlen)
			{
				minlen=len;
				stind=st;
			}
		}
	}
	return minlen;
}
int main() {
	string s;
	cin>>s;
	cout<<solve(s);
	
	// your code goes here
	return 0;
}