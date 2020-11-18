#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
You are given two positive integers n (1≤n≤109) and k (1≤k≤100). Represent the number n as the sum of k positive
 integers of the same parity (have the same remainder when divided by 2).

In other words, find a1,a2,…,ak such that all ai>0, n=a1+a2+…+ak and either all ai are even or all ai are odd at the same time.

If such a representation does not exist, then report it.



*/
int main() {
	ll a,t,n,k,i,j,l,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		 a = n-(k-1);
		 if(a>0&&a%2)
		 {
		 	cout<<"YES\n";
		 	for(i=1;i<=k-1;i++) cout<<"1 ";
		 	cout<<a<<endl;
		 	continue;
		 }
		 a = n-(k-1)*2;
		 if(a>0&&a%2==0)
		 {
		 	cout<<"YES\n";
		 	for(i=1;i<=k-1;i++) cout<<"2 ";
		 	cout<<a<<endl;
		 	continue;
		 }
		 cout<<"NO\n";
	}
	// your code goes here
	return 0;
}