#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cntsub(ll a[],ll n)
{
	ll i,j,len=1,cnt=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]>=a[i])
		len++;
		else
		{
		  cnt+=(len*(len+1))/2;
		  len=1;
		}
	}
	//if last len>1
// 	if(len>1)
	cnt+=(len*(len+1))/2;
	return cnt;
}
int main() {
	ll t,n,a[100005],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		cout<<cntsub(a,n)<<endl;
	}
	// your code goes here
	return 0;
}