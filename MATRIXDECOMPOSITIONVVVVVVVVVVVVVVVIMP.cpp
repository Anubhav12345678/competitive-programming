#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
ll mod  = 1000000007;
/*
You are given a square matrix M with N rows (numbered 1 through N) and N columns (numbered 1 through N). Initially,
 all the elements of this matrix are equal to A. The matrix is broken down in N steps (numbered 1 through N); note that 
 during this process, some elements of the matrix are simply marked as removed, but all elements are still indexed in the
  same way as in the original matrix. For each valid i, the i-th step consists of the following:

Elements M1,N−i+1,M2,N−i+1,…,Mi−1,N−i+1 are removed.
Elements Mi,N−i+1,Mi,N−i+2,…,Mi,N are removed.
Let's denote the product of all 2i−1 elements removed in this step by pi. Each of the remaining elements of the matrix
 (those which have not been removed yet) is multiplied by pi.
Find the sum p1+p2+p3+…+pN. Since this number could be very large, compute it modulo 109+7.



*/
ll power(ll n,ll ind)
{
	if(ind==0)
	return 1;
	if(ind==1)
	return n;
	ll x = power(n,ind/2)%mod;
	x = (x*x)%mod;
	if(ind%2==0)
	return x%mod;
	else
	return (x*n)%mod;
}
int main() {
	ll i,j,a,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>a;
		ll ans=0LL;
		for(i=1;i<=n;i++)
		{
			k = power(a,2*i-1)%mod;
			ans = (ans+k)%mod;
			a=(a*k)%mod;
		}
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}