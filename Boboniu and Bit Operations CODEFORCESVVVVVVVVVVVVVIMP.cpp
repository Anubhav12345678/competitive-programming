#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*

Boboniu likes bit operations. He wants to play a game with you.

Boboniu gives you two sequences of non-negative integers a1,a2,…,an and b1,b2,…,bm.

For each i (1≤i≤n), you're asked to choose a j (1≤j≤m) and let ci=ai&bj, where & denotes the bitwise AND operation.
 Note that you can pick the same j for different i's.

Find the minimum possible c1|c2|…|cn, where | denotes the bitwise OR operation.

*/
bool  isval(ll x,vector<ll> &a, vector<ll> &b){
	bool f=false;
	ll i,j,k,l,n=a.size();
	ll m=b.size();
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<m;j++)
		if(((a[i]&b[j])|x)==x)
		{
			f=true;
			break;
		}
		if(f==0) return false;
	}
	
	return true;
}
ll solve(vector<ll> &a,vector<ll> &b){
	ll i,j,k,l,n=a.size();
	ll m = b.size();
	ll res=0LL;
	for(i=0;i<(1<<9);i++){
		if(isval(i,a,b)) return i;
	}
	return 0;
}
int main() {
	
	ll n,m,i,j;
	cin>>n>>m;
	vector<ll> a(n), b(m);
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<m;i++) cin>>b[i];
	cout<<solve(a,b)<<endl;
	// your code goes here
	return 0;
}