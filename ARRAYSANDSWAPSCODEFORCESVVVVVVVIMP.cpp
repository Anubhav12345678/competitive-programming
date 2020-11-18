#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
You are given two arrays a and b both consisting of n positive (greater than zero) integers. 
You are also given an integer k.

In one move, you can choose two indices i and j (1≤i,j≤n) and swap ai and bj (i.e. ai becomes bj
 and vice versa). Note that i and j can be equal or different (in particular,
  swap a2 with b2 or swap a3 and b9 both are acceptable moves).

Your task is to find the maximum possible sum you can obtain in the array a if you can 
do no more than (i.e. at most) k such moves (swaps).

You have to answer t independent test cases.
*/
ll solve(ll a[],ll b[],ll n,ll k)
{
	ll i,j,l,ans=0LL;
	sort(a,a+n);
	sort(b,b+n,greater<>());
	for(i=0;i<n;i++)
	{
		if(k>0)
		{
			if(a[i]<b[i])
			{
				ans+=b[i];
				k--;
			}
			else
			ans+=a[i];
		}
		else
		ans+=a[i];
	}
	return ans;
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll a[n],b[n];
		for(i=0;i<n;i++) cin>>a[i];
		for(j=0;j<n;j++) cin>>b[j];
		cout<<solve(a,b,n,k)<<endl;
	}
	// your code goes here
	return 0;
}