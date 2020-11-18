#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
Alexander is a well-known programmer. Today he decided to finally go out and play football, but with the first hit 
he left a dent on the new Rolls-Royce of the wealthy businessman Big Vova. Vladimir has recently opened a store on
 the popular online marketplace "Zmey-Gorynych", and offers Alex a job: if he shows his programming skills by solving 
 a task, he'll work as a cybersecurity specialist. Otherwise, he'll be delivering some doubtful products for the next two years.

You're given n positive integers a1,a2,…,an. Using each of them exactly at once, you're to make such sequence b1,b2,…,bn 
that sequence c1,c2,…,cn is lexicographically maximal, where ci=GCD(b1,…,bi) - the greatest common divisor of the first i
 elements of b.

Alexander is really afraid of the conditions of this simple task, so he asks you to solve it.

A sequence a is lexicographically smaller than a sequence b if and only if one of the following holds:

a is a prefix of b, but a≠b;
in the first position where a and b differ, the sequence a has a smaller element than the corresponding element in b.

*/
void solve(vector<ll> &a){
	ll i,j,k,l,n=a.size();
	vector<ll> b(n), vis(n,0);
	ll d=0;
	for(i=0;i<n;i++){
		ll ind=0;
		ll maxi =0;
		for(j=0;j<n;j++){
			if(!vis[j]&&__gcd(d,a[j])>maxi){
				maxi = __gcd(d,a[j]);
				ind=j;
				// d=maxi;
			}
		}
		vis[ind]=1;
		b[i]=a[ind];
		d=maxi;
	}
	
	for(auto v: b) cout<<v<<" ";
	cout<<endl;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n);
		for(ll i=0;i<n;i++) cin>>a[i];
		solve(a);
	}
	// your code goes here
	return 0;
}