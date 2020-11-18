#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
	ll i,j,k,l,maxendinghere=1,minendginghere=1,maxsofar=1;
	bool fg=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>0)
		{
           maxendinghere = maxendinghere*a[i];
           minendginghere = min(minendginghere*a[i],1);
           fg=1;
		}
		else if(a[i]==0)
		{
			//maxproducthere and minproduct here cant end so both are made equal to 1.
          maxendinghere=1;
          minendginghere=1;
		}
		else if(a[i]<0)
		{
          ll tmp = maxendinghere;
          maxendinghere = max(minendginghere*a[i]);
          minendginghere = a[i]*maxendinghere;
		}
		maxsofar = max(maxsofar,maxendinghere);
	}
	if(fg==0&&maxsofar==1)
	{
		// means that there is no positive element and all elements are zero or there is only one element and that is negative
		return 0;
	}
	return maxsofar;
}







