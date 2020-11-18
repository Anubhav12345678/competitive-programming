#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Tambourine has prepared a fitness program so that she can become more fit! The program is made of N sessions.
 During the i-th session, Tambourine will exercise for Mi minutes. The number of minutes she exercises in each 
 session are strictly increasing.

The difficulty of her fitness program is equal to the maximum difference in the number of minutes between any two consecutive
 training sessions.

To make her program less difficult, Tambourine has decided to add up to K additional training sessions to her fitness program.
 She can add these sessions anywhere in her fitness program, and exercise any positive integer number of minutes in each of them.
  After the additional training session are added, the number of minutes she exercises in each session must still be strictly 
  increasing. What is the minimum difficulty possible?


*/
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	ll x = t;
	while(t--){
		cin>>n>>k;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		ll lo=1;
		ll hi = a[1]-a[0];
		for(i=1;i<n-1;i++)
		hi  =max(hi,a[i+1]-a[i]);
		ll ans=hi;
		
		while(lo<=hi){
			ll m = (lo+hi)/2;
		  ll session=a[0];
		  ll p=0;
		  i=1;
		  while(i<n){
		  	if((session+m)<a[i])
		  	{
		  		session+=m;
		  		p++;
		  	}
		  	else{
		  		session = a[i];
		  		i++;
		  	}
		  }
		  if(p<=k)
		  {
		  	ans = m;
		  	hi=m-1;
		  }
		  else
		  lo=m+1;
		}
		cout<<"Case #"<<x-t<<": "<<ans<<endl;
	}
	// your code goes here
	return 0;
}