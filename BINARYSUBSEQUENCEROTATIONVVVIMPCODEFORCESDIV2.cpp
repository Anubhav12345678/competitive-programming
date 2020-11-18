#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(string &s,string &t){
	ll i,j,k,l,n=s.size();
	ll a=0,b=0;
	if(s==t) return 0;
	for(i=0;i<n;i++){
		if(s[i]=='1') a++;
		if(t[i]=='1') b++;
	}
	if(a!=b) return -1;
	ll ones=0;
	ll zeroes=0;
	for(i=0;i<n;i++){
		if(s[i]!=t[i]){
			if(s[i]=='0'&&t[i]=='1') {
				if(zeroes) zeroes--;
				ones++;
			}
			else if(s[i]=='1'&&t[i]=='0'){
				if(ones) ones--;
				zeroes++;
			}
		}
	}
	return zeroes+ones;
}
int main() {
	ll i,j,k,n;
	string s,t;
	cin>>n>>s>>t;
	cout<<solve(s,t);
	// your code goes here
	return 0;
}
/*
Naman has two binary strings s and t of length n (a binary string is a string which only consists of the characters "0" and "1").
 He wants to convert s into t using the following operation as few times as possible.

In one operation, he can choose any subsequence of s and rotate it clockwise once.

For example, if s=1110100, he can choose a subsequence corresponding to indices (1-based) {2,6,7} and rotate them clockwise. The 
resulting string would then be s=1010110.

A string a is said to be a subsequence of string b if a can be obtained from b by deleting some characters without changing the
 ordering of the remaining characters.

To perform a clockwise rotation on a sequence c of size k is to perform an operation which sets c1:=ck,c2:=c1,c3:=c2,…,ck:=ck−1
 simultaneously.

Determine the minimum number of operations Naman has to perform to convert s into t or say that it is impossible.

*/