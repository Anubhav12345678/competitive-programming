#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
	ll i,j,k,cnt=0;
	i=0;
	j=n-1;
	while(i<=j)
	{
		if(a[i]==a[j])
		{
			i++;
			j--;
		}
		else
		{
			while(i<j)
			{
				if(a[i]<a[j])
				{
					a[i+1]+=a[i];
					i++;
				}
				else
				{
					a[j-1]+=a[j];
					j--;
				}
				cnt++;
				if(a[i]==a[j])
				break;
			}
		}
	}
	return cnt;
}
int main() {
	ll t,n,a[100001],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<solve(a,n)<<endl;
	}
	// your code goes here
	return 0;
}