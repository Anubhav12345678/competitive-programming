#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll solve(string s)
{
	ll x,i,j,k,l,res=0;
	ll n = s.size();
	// cout<<n<<endl;
	ll presum[n];
	memset(presum,0,sizeof(presum));
	presum[0] = (s[0]=='0')?0:1;
	// cout<<presum[0]<<endl;
	for(i=1;i<n;i++)
	{
		// cout<<"s["<<i<<"] = "<<s[i]<<endl;
		if(s[i]=='1')
		{
			// cout<<"eneter if\n";
		presum[i] = presum[i-1]+1;
		}
		else
		presum[i] = presum[i-1];
		// cout<<"presum["<<i<<"] = "<<presum[i]<<" ";
	}
	// cout<<endl;
	for(x=1;x*x+x<=n;x++)
	{
		for(i=0;i<n-(x*x+x)+1;i++)
		{
			j=i+(x*x+x)-1;
			if(i==0)
			{
			  if(presum[j]==x)
			  res++;
			}
			else
			{
				if((presum[j]-presum[i-1])==x)
				res++;
			}
		}
	}
	return res;
	
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