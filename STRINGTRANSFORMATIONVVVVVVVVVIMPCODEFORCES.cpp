#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<set>
/*
Note that the only difference between String Transformation 1 and String Transformation 2 is in the move Koa does. 
In this version the letter y Koa selects must be strictly greater alphabetically than x (read statement for better understanding).
 You can make hacks in these problems independently.

Koa the Koala has two strings A and B of the same length n (|A|=|B|=n) consisting of the first 20 lowercase English alphabet 
letters (ie. from a to t).

In one move Koa:

selects some subset of positions p1,p2,…,pk (k≥1;1≤pi≤n;pi≠pj if i≠j) of A such that Ap1=Ap2=…=Apk=x (ie. all letters on 
this positions are equal to some letter x).
selects a letter y (from the first 20 lowercase letters in English alphabet) such that y>x (ie. letter y is strictly greater
 alphabetically than x).
sets each letter in positions p1,p2,…,pk to letter y. More formally: for each i (1≤i≤k) Koa sets Api=y.
Note that you can only modify letters in string A.

Koa wants to know the smallest number of moves she has to do to make strings equal to each other (A=B) or to determine 
that there is no way to make them equal. Help her!

*/
int main() {
	
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		string a,b;
		cin>>a>>b;
		bool f=0;
	    for(i=0;i<n;i++)
	    if(a[i]>b[i])
	    {
	    	f=1;
	    	break;
	    }
		if(f){
			cout<<"-1"<<endl;
			continue;
		}
		ll ans=0;
		for(char c='a';c<='t';c++){
			char mn = 't';
			vector<ll> tmp;
			for(i=0;i<n;i++){
				if(a[i]!=b[i]&&a[i]==c){
					tmp.pb(i);
					mn = min(mn,b[i]);
				}
			}
			if(tmp.size()!=0){
				ans++;
				for(auto x:tmp)
				a[x]=mn;
			}
		}
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}