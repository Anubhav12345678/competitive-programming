#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
ll solve(ll n)
{
	if(n==1)
	return 3;
	if(n==2)
	return 8;
	if(n==3)
	return 19;
	ll x = 1+2*n+(n*(n-1))/2+(n*(n-1)*(n-2))/2+(n*(n-1));
	return x;
}
int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
	// your code goes here
	return 0;
}