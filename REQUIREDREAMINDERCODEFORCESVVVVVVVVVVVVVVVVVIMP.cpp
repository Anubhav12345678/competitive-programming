#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll x,ll y,ll n)
{
	if(n-n%x+y<=n)
	return n-n%x+y;
	else
	return n-n%x-(x-y);
}
int main() {
	ll t,x,y,n;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>n;
		cout<<solve(x,y,n)<<endl;
	}
	// your code goes here
	return 0;
}
/*

You are given three integers x,y and n. Your task is to find the maximum integer k such that 0≤k≤n that kmodx=y, where mod is modulo operation. Many programming languages use percent operator % to implement it.

In other words, with given x,y and n you need to find the maximum possible integer from 0 to n that has the remainder y modulo x.

You have to answer t independent test cases. It is guaranteed that such k exists for each test case.



*/