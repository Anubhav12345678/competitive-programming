#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll val(ll a,ll b)
{
	return ((a%2)?(2*a+1):(2*a))+((b%2)?(2*b-1):(2*b));
}
int main() {
	ll a,b,t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		ll z = min(x,y);
		cout<<(2*z+val(x-z,y-z))<<endl;
	}
	
	// your code goes here
	return 0;
}