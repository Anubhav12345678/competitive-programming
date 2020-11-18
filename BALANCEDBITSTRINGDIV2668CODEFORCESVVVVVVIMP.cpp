#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*

A bitstring is a string consisting only of the characters 0 and 1. A bitstring is called k-balanced if every substring
 of size k of this bitstring has an equal amount of 0 and 1 characters (k2 of each).

You are given an integer k and a string s which is composed only of characters 0, 1, and ?. You need to determine whether
 you can make a k-balanced bitstring by replacing every ? characters in s with either 0 or 1.

A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters
 from the beginning and several (possibly, zero or all) characters from the end.
*/
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		string s;
		cin>>n>>k>>s;
		vector<char> v(k,'?');
		bool ok=1;
		for(i=0;i<k;i++){
			for(j=i;j<n;j+=k)
			{
				if(s[j]=='?') continue;
				if(v[i]=='?'||v[i]==s[j]) v[i]=s[j]; // s[j]!='?' so we have to fill by that cah '0' or '1'
				else if(v[i]!=s[j]) ok=false;
 			}
		}
		
		ll c1=0,c2=0;
		for(i=0;i<k;i++){
			if(v[i]=='1') c1++;
			else if(v[i]=='0') c2++;
		}
		
		if(c1>k/2||c2>k/2) ok=0;
		if(ok) cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	// your code goes here
	return 0;
}