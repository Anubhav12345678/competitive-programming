#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*
You are given an array Arr that contains N integers. In one step, you can pick an element from position p and place
 it before or after some other elements. For example, if you are given an array  ={}, then you can pick  and place
  it after . Therefore, the updated array is  ={}. 

Your task is to determine the minimum number of steps that is required to sort the data in increasing or decreasing order. 

Input format

First line: A single integer  denoting the size of array 
Second line:  space-separated integers, where the  integer denotes 


*/
ll ceilind(ll l,ll r,vector<ll> &v,ll k){
	while((r-l)>1){
		int m = (l+r)/2;
		if(v[m]>=k)
		r=m;
		else
		l=m;
	}
	return r;
}
ll solve(vector<ll> &v){
	ll i,j,k,l,n=v.size();
	if(n==0) return 0;
	vector<ll> t(n,0);
	ll len=1;
	t[0] = v[0];
	for(i=1;i<n;i++){
		if(v[i]<t[0])
		t[0]= v[i];
		else if(v[i]>t[len-1])
		t[len++] = v[i];
		else
		t[ceilind(-1,len-1,t,v[i])] = v[i];
	}

	return len;
}
int main(){
  ll i,j,k,l,n;
  cin>>n;
  vector<ll> v(n);
  for(i=0;i<n;i++) cin>>v[i];
 ll ans1=n-solve(v);
    reverse(v.begin(),v.end());
    ll ans2=n-solve(v);
    cout<<min(ans1,ans2);
    return 0;
}