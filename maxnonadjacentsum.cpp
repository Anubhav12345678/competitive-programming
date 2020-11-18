#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maxnonadjacentsum(ll a[],ll n)
{
	ll exc_new=0,exc=0,inc=0;
	for(ll i=0;i<n;i++)
	{
		exc_new = max(exc,inc);
		inc = exc+a[i];//as no 2 ele can be adjacent
		exc = exc_new;
	}
	return max(inc,exc);
}
int main() {
	ll n,a[100001],i;
	cin>>n;
	for(ll i=0;i<n;i++)
	cin>>a[i];
	cout<< maxnonadjacentsum(a,n)<<endl;
	// your code goes here
	return 0;
}