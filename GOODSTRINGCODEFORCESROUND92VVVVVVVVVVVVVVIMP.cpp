#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Let's call left cyclic shift of some string t1t2t3…tn−1tn as string t2t3…tn−1tnt1.

Analogically, let's call right cyclic shift of string t as string tnt1t2t3…tn−1.

Let's say string t is good if its left cyclic shift is equal to its right cyclic shift.

You are given string s which consists of digits 0–9.

What is the minimum number of characters you need to erase from s to make it good?
*/
ll solve(string s){
	ll k,l,n=s.size(),x;
	ll tm=0,ans=0;
	for(char i='0';i<='9';i++){
		for(char j='0';j<='9';j++){
			tm=0;
			for(x=0;x<n;x++){
				if(tm&1)
				{
					if(s[x]==j) tm++;
				}
				else {
					if(s[x]==i) tm++;
				}
			}
			if(i!=j)
				 if(tm&1)
				 tm--;
				 
				 ans = max(ans,tm);
		}
	}
	return n-ans;
}
int main() {
	
	ll t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<solve(s)<<endl;
	}
	// your code goes here
	return 0;
}
/*
Let's call left cyclic shift of some string t1t2t3…tn−1tn as string t2t3…tn−1tnt1.

Analogically, let's call right cyclic shift of string t as string tnt1t2t3…tn−1.

Let's say string t is good if its left cyclic shift is equal to its right cyclic shift.

You are given string s which consists of digits 0–9.

What is the minimum number of characters you need to erase from s to make it good?


*/