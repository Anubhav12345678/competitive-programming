#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll dp[805];
	dp[0]=1;
    for(ll i=0;i<805;i++)
    dp[i] = dp[i-1]-i+1;
    ll t,n;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	cout<<dp[n]<<endl;
    }
	// your code goes here
	return 0;
}