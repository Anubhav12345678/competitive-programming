#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll l,g,r,t;
	cin>>t;
	while(t--)
	{
		cin>>l>>r>>g;
		if(r<g)
		{
			cout<<0<<endl;
			continue;
		}
		if(l%g)
		l = l-(l%g)+g;
		r = r-r%g;
	    ll c = (r-l)/g+1;
	    if(l==r&&l!=g)
	    c=0;
	    cout<<c<<endl;
	}
	// your code goes here
	return 0;
}