#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll x,y,z,s=0;
	cin>>x>>y>>z;
    ll r1 = x%z;
    ll r2 = y%z;
    if(r1+r2<z)
    {
    	cout<<(x+y)/z<<" "<<0<<endl;
    }
    else
    {
    	cout<<(x+y)/z<<" "<<(z-max(r1,r2))<<endl;
    }
	// your code goes here
	return 0;
}