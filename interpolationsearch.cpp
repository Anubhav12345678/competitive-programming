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
// if ele r uniformly distributed its complexity is O(log(log n))
ll interpolationsearch(ll a[],ll n,ll x)
{
	ll lo=0;
	ll hi = n-1;
	while(lo<=hi && x>=a[lo] && x<=a[hi])
	{
		if(lo==hi)
		{
			if(a[lo]==x) return lo;
			return -1;
		}

		ll pos = lo + (((double)(x-a[lo])/(a[hi]-a[lo]))*(hi-lo));  //this search is assuming uniform distribution so interpolation is applied
		if(a[pos]==x)
			return pos;
		if(a[pos]<x)
			lo = pos+1;
		if(a[pos]>x)
			hi = pos-1;
	}
	return -1;
}