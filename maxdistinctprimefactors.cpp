#include <bits/stdc++.h>
using namespace std;
#define ll long long
//number having max no of distinct prime factors from m to n
ll countmaxnumberofprimefactors(ll m,ll n)
{
	ll factorcount[n+1],i,j;
	bool isprime[n+1];
	memset(factorcount,0,sizeof(factorcount));
	memset(isprime,true,sizeof(isprime));
	for(i=2;i<=n;i++)
	{
	//	only if i is a prime number
		if(isprime[i])
		{
			factorcount[i]=1;//primenumber
			for(j=i*2;j<=n;j+=i)
			{
				factorcount[j]++;
				isprime[j] = false;
			}
		}
	}
	// for(i=2;i<=n;i++)
	// cout<<factorcount[i]<<" ";
	
	ll maxi = factorcount[m];
	for(i=m+1;i<=n;i++)
	{
		if(factorcount[i]>maxi)
		maxi = i;
	}
	return maxi;
}
int main() {
	ll m,n;
	cin>>m>>n;
	cout<<countmaxnumberofprimefactors(m,n);
	
	// your code goes here
	return 0;
}