#include <bits/stdc++.h>
using namespace std;
#define ll long long
// ll solve(ll l,ll r,ll g)
// {
// 	if(r<g)
// 	return 0;
// 	ll x = (l%g)?(l/g+1):(l/g);
// 	ll y = r/g;
// 	ll p = x*g;
// 	ll q = y*g;
// 	// cout<<x<<" "<<y<<" "<<p<<" "<<q<<endl;
// 	if(x==y)
// 	{
// 	    if(x==g)
// 	    return 1;
// 	    else
// 	    return 0;
// 	}
// 	return y-x+1;
	
// }
int main() {
	ll l,r,g,t;
	cin>>t;
	while(t--)
	{
		cin>>l>>r>>g;
// 		cout<<solve(l,r,g)<<endl;
         ll d = (r/g)-(l-1)/g;
         if(d!=1)
         cout<<d<<endl;
         else if(l<=g&&g<=r)
         cout<<1<<endl;
         else
         cout<<0<<endl;
		
	}
	// your code goes here
	return 0;
}