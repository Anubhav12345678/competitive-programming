#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t,d,i,j,noap=0,nominp;
	char s[1005];
	ll nomar;
	cin>>t;
	while(t--)
	{
		nomar=0;
		noap=0;
		nominp=0;
		cin>>d;
		cin>>s;
		for(i=0;i<d;i++)
		if(s[i]=='P')
		noap++;
		nominp = (ll)ceil(0.75*d);
		if(noap>=nominp)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			ll diff= nominp-noap;
			nomar=0;
			for(i=2;i<d-2;i++)
			if(s[i]=='A'&&(s[i-1]=='P'||s[i-2]=='P')&&(s[i+1]=='P'||s[i+2]=='P'))
			nomar++;
			if(nomar>=diff)
			cout<<min(nomar,diff)<<endl;
			else
			cout<<-1<<endl;
		}
		
	}
	// your code goes here
	return 0;
}