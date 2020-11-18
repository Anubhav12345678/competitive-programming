#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define ff first
#define se second
const ll maxn = 10000005;
bool isprime[maxn];
ll small[maxn];
void fill(){
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=0;
	for(ll i=2;i<maxn;i++)
	{
		isprime[i]=1;
	 small[i]=i;
	}
	for(ll i=2;i<maxn;i++){
		// cout<<"i = "<<i<<endl;
		if(isprime[i]){
			// cout<<"i = "<<i<<endl;
			small[i]=i;
			for(ll j=2*i;j<maxn;j+=i){
				// if(isprime[j]){
				   small[j]=i;
					isprime[j]=0;
				    // cout<<"small["<<j<<"] = "<<small[j]<<" i = "<<i<<endl;
			}
		}
	}
	// for(ll i=2;i<10;i++) cout<<small[i]<<" ";
}
int main() {
	fill();
	// for(ll i=0;i<100;i++) cout<<small[i]<<endl;
	ll i,j,k,l,n,m;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	vector<pair<ll,ll> > ans;
	for(i=0;i<n;i++){
		k = a[i];
		ll z = small[a[i]];
		// cout<<"k = "<<k<<"z = "<<z<<endl;
		ll p=1,d1,d2;
		while(k%z==0){
			k/=z;
			p = p*z;
		}
		d1 = p;
		d2 = a[i]/p;
		if(d1>1&&d2>1&&__gcd(d1+d2,a[i])==1)
		ans.push_back({d1,d2});
		else
		ans.push_back({-1,-1});
	}
	
	for(i=0;i<ans.size();i++)
	cout<<ans[i].ff<<" ";
	cout<<endl;
	
	for(i=0;i<ans.size();i++)
	cout<<ans[i].se<<" ";
	// your code goes here
	return 0;
}
/*

You are given n integers a1,a2,…,an.

For each ai find its two divisors d1>1 and d2>1 such that gcd(d1+d2,ai)=1 (where gcd(a,b) is the greatest common divisor of a and b) or say that there is no such pair.

Input
The first line contains single integer n (1≤n≤5⋅105) — the size of the array a.

The second line contains n integers a1,a2,…,an (2≤ai≤107) — the array a.


*/