#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
  The answer is n1+n2−2x, where x is the maximum number of stones we can remove from both piles.

We can only remove up to 1+2+⋯+m=m(m+1)2 stones from both piles. If n1 and n2 are both at least m(m+1)2, then this is the maximum number we can remove. Otherwise, we can remove up to min(n1,n2) from both piles. Therefore, x=min(m(m+1)2,n1,n2).



*/
int main() {
	ll n1,n2,m,t;
	cin>>t;
	while(t--)
	{
		cin>>n1>>n2>>m;
		ll x = min(min(n1,n2),((m*(m+1))/2));// xis the min number of stones which can be removed
		cout<<(n1+n2-2*x)<<endl;
	}
	// your code goes here
	return 0;
}