#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<map>
#define ff first
#define se second
/*


You are given an array a consisting of n positive integers.

Initially, you have an integer x=0. During one move, you can do one of the following two operations:

Choose exactly one i from 1 to n and increase ai by x (ai:=ai+x), then increase x by 1 (x:=x+1).
Just increase x by 1 (x:=x+1).
The first operation can be applied no more than once to each i from 1 to n.

Your task is to find the minimum number of moves required to obtain such an array that each its element is divisible by k (the value k is given).

You have to answer t independent test cases.

*/
ll solve(vector<ll> &v,ll K)
{
	ll i,j,k,l,n=v.size();
	map<ll,ll> mp;
	for(i=0;i<n;i++)
	{
		mp[v[i]%K]++;
	}
	ll mx=0,ans=0;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->ff!=0)
		{
			ll cnt = it->se;
			ans = max(ans,cnt*K-it->ff);
		}
	}
	if(ans) ans++;
	return ans;
}
int main() {
	ll i,j,k,l,n,K,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>K;
		vector<ll> v(n);
		for(i=0;i<n;i++) 
	    cin>>v[i];
	    cout<<solve(v,K)<<endl;
 	}
	// your code goes here
	return 0;
}