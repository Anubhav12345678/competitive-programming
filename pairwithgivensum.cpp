#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
int main() {
	ll hash[100001],i,j,t,n,a[100001],sum;
	cin>>t;
	while(t--)
	{
		memset(hash,0,sizeof(hash));
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			hash[a[i]]++;
		}
		cin>>sum;
		ll f=0;
		for(i=0;i<n;i++)
		{
			if(sum>=a[i])
			{
				if(hash[sum-a[i]]>=1)
				{
					f=1;
					break;
				}
			}
		}
		if(f==0)
		cout<<"no";
		else
		cout<<"yes";
		
	}
	
	
	// your code goes here
	return 0;
}