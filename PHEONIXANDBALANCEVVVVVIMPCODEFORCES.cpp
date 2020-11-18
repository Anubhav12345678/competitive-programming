#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
Phoenix has n coins with weights 21,22,…,2n. He knows that n is even.

He wants to split the coins into two piles such that each pile has exactly n2 coins and the difference of
 weights between the two piles is minimized. Formally, let a denote the sum of weights in the first pile,
  and b denote the sum of weights in the second pile. Help Phoenix minimize |a−b|, the absolute value of a−b.
*/
ll power[32];
void fill()
{
	power[0]=1LL;
	for(int i=1;i<=30;i++)
	power[i] = power[i-1]*2;
}
int main() {
	fill();
	ll n,t,i,j,k,l;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		cout<<2<<endl;
		else{
			ll ans=0LL;
			ll k=2;
			for(i=2;i<=n;i+=2)
			{
				ans=ans+k;
				k*=2;
			}
			cout<<ans<<endl;
		}
	}
	// your code goes here
	return 0;
}
/*
Phoenix has n coins with weights 21,22,…,2n. He knows that n is even.

He wants to split the coins into two piles such that each pile has exactly n2 coins and the difference of
 weights between the two piles is minimized. Formally, let a denote the sum of weights in the first pile,
  and b denote the sum of weights in the second pile. Help Phoenix minimize |a−b|, the absolute value of a−b.
*/