#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
	ll maxsofar=0,maxendinghere=0,i,j,k;
	for(i=0;i<n;i++)
	{
		maxendinghere+=a[i];
		if(maxendinghere<0)
		maxendinghere=0;
		if(maxsofar<maxendinghere)
		maxsofar = maxendinghere;
	}
	return maxsofar;
}
int main() {
	ll a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    ll n = sizeof(a)/sizeof(a[0]); 
    // ll max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " <<solve(a,n); 
    return 0; 
	// your code goes here
	return 0;
}