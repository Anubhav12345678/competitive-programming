#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

You are given a binary string S with length N and an integer K, which is a divisor of N. A string is said to be K-foldable if it
 can be changed to a string with length K by repeating the following process without any collisions (defined below):

Select the prefix of the current string S with length 2K. (Note that as long as the length of S is greater than K, this prefix 
always exists.)
For each i (1≤i≤K), check if the 2K−i+1-th character of S is equal to the i-th character of S ― if they are not equal, there is a 
collision and the process is invalid.
Erase the prefix of S with length K.
Your goal is to reorder the characters of S (possibly leaving this string unchanged) in such a way that the resulting string S is
 a K-foldable string. Find a way to do that or determine that it is impossible. If there are multiple solutions, find the
  lexicographically smallest rearranged string which is K-foldable.


*/
void solve(string &s,ll k){
	ll i,j,l,n,a,b,c,p,q;
	n = s.size();
	ll r = n/k;
	ll z=0,o=0;
	for(i=0;i<n;i++){
		if(s[i]=='0') z++;
		else
		o++;
	}
	
	for(i=0;i<=k;i++){
		a= i;
		b = k-i;
		if((a*r)==z&&(b*r)==o){
			string news="";
			if(a>0)
			news+=string(a,'0');
			if(b>0)
			news+=string(b,'1');
			string rev = news;
			reverse(rev.begin(),rev.end());
			for(i=0;i<r;i++){
				if(i%2==0)
				cout<<news;
				else
				cout<<rev;
			}
			cout<<endl;
			return;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
int main() {
	
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		string s;
		cin>>n>>k>>s;
		solve(s,k);
	}
	// your code goes here
	return 0;
}