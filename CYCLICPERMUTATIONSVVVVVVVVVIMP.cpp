#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
const ll sz = 1000001;
ll fac[sz];
void fact(){
	memset(fac,0,sizeof(fac));
	fac[0]=fac[1] = 1;
	for(ll i=2;i<sz;i++){
		fac[i] = (i*(fac[i-1]))%mod;
	}
}
ll power[sz];
void fill(){
	power[0]=1LL;
	for(ll i=1;i<sz;i++)
	power[i] = (2*power[i-1])%mod;
}
int main() {
	fact();
	fill();
	ll i,j,k,l,n,t,a,b;
	// cin>>t;
	t=1;
	while(t--){
		cin>>n;
		cout<<(fac[n]-power[n-1]+mod)%mod<<endl;
	}
	
	// your code goes here
	return 0;
}
/*
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order.
 For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) 
 and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

Consider a permutation p of length n, we build a graph of size n using it as follows:

For every 1≤i≤n, find the largest j such that 1≤j<i and pj>pi, and add an undirected edge between node i and node j
For every 1≤i≤n, find the smallest j such that i<j≤n and pj>pi, and add an undirected edge between node i and node j
In cases where no such j exists, we make no edges. Also, note that we make edges between the corresponding indices,
 not the values at those indices.

For clarity, consider as an example n=4, and p=[3,1,4,2]; here, the edges of the graph are (1,3),(2,1),(2,3),(4,3).

A permutation p is cyclic if the graph built using p has at least one simple cycle.

Given n, find the number of cyclic permutations of length n. Since the number may be very large, output it modulo 109+7.

Please refer to the Notes section for the formal definition of a simple cycle


*/