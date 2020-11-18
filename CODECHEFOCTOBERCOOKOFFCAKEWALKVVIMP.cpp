#include <bits/stdc++.h>
using namespace std;
#define ll long long
// bool  powerof2(ll n,ll &cnt)
// {
// 	while(n%2==0)
// 	{
// 	n/=2;
// 	cnt++;
// 	}
// 	return n==1;
// }
// bool  powerof2(ll n,ll &cnt)
// {
// 	while(n%5==0)
// 	{
// 	n/=5;
// 	cnt++;
// 	}
// 	return n==1;
// }

int main() {
	ll t,n,i,j,k,l,a,b,c;
	cin>>t;
	while(t--)
	{
		ll cnt2=0,cnt5=0;
		cin>>n;
		while(n%2==0)
	    {
	      n/=2;
	      cnt2++;
	    }
	    while(n%5==0)
	    {
	      n/=5;
	      cnt5++;
	    }
	    if(n!=1)
	    cout<<"No\n";
	    else
	    {
	    	if(cnt2<cnt5||cnt2>2*cnt5)
	    	cout<<"No\n";
	    	else
	    	cout<<"Yes\n";
	    }
	}
	// your code goes here
	return 0;
}