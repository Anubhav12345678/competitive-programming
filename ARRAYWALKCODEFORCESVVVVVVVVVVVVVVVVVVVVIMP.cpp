#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
ll dp[100005][6];
ll solve(vector<ll> &v,ll i,ll k,ll z){
	if(k<=0||i>=v.size()||i<0) return 0;
	if(dp[i][z]!=-1) return dp[i][z];
	
	ll val=0;
	if(i<v.size()) 
	val = max(val,v[i]+solve(v,i+1,k-1,z));
	if(i>=0&&z>0)
	val = max(val,v[i]+solve(v,i-1,k-1,z-1));
	
	return dp[i][z] = val;
}
int main() {
	
	ll z,i,j,k,l,n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>k>>z;
		vector<ll> v(n);
		for(i=0;i<n;i++) cin>>v[i];
		memset(dp,-1,sizeof(dp));
		cout<<solve(v,1,k,z)+v[0]<<endl;
	}
	// your code goes here
	return 0;
}
/*
You are given an array a1,a2,…,an, consisting of n positive integers.

Initially you are standing at index 1 and have a score equal to a1. You can perform two kinds of moves:

move right — go from your current index x to x+1 and add ax+1 to your score. This move can only be performed if x<n.
move left — go from your current index x to x−1 and add ax−1 to your score. This move can only be performed if x>1. Also, you can't perform two or more moves to the left in a row.
You want to perform exactly k moves. Also, there should be no more than z moves to the left among them.

What is the maximum score you can achieve?
*?