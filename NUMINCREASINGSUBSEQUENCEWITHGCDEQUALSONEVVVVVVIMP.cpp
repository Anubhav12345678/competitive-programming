#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*
Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:

Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length  and . A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 

She finds this task really easy, and thinks that you can do it too. Can you?

*/
ll mod = 1e9+7;
ll solve(vector<ll > &v){
	ll i,j,k,l,n=v.size();
	ll ans=0LL;
	k = (ll)(101);
	ll dp[n][k];
	memset(dp,0,sizeof(dp));
	// dp[i][j]  is the number of subsequences ending at this point i having gcd as j
	for(i=0;i<n;i++){
		dp[i][v[i]] = 1;
		for(j=i-1;j>=0;j--){
			if(v[i]>v[j]){
				for(ll p =1;p<=100;p++)
				{
					ll g = __gcd(v[i],p);
					dp[i][g] = (dp[i][g]%mod+dp[j][p]%mod);
				}
			}
		}
	}
	// for(i=0;i<n;i++)
	// cout<<dp[i][1]<<" ";
	for(i=0;i<n;i++)
	ans = (ans+dp[i][1]%mod)%mod;
	
	return ans;
}
int main() {
	
	ll i,j,k,l,n,t;
	// cin>>t;
	t=1;
	while(t--){
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++) cin>>v[i];
		cout<<solve(v)<<endl;
	}
	// your code goes here
	return 0;
}