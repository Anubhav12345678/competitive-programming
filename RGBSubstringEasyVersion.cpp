#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<limits.h>
int main() {
	string t="RGB";
	ll cur=0,offset=0,i,j,k,l,q,n,ans=INT_MAX,p;
	string s;
	cin>>q;
	while(q--)
	{
		ans=INT_MAX;
		cin>>n>>k;
		cin>>s;
		// ll n=s.size();
		for(i=0;i<n-k+1;i++)
		{
			for(offset=0;offset<3;offset++)
			{
				cur=0;
				for(p=0;p<k;p++)
				{
					if(s[i+p]!=t[(offset+p)%3])
					cur++;
				}
				ans = min(cur,ans);
			}
		}
		cout<<ans<<endl;
	}
	
	// your code goes here
	return 0;
}