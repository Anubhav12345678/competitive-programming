#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Alica and Bob are playing a game.

Initially they have a binary string s consisting of only characters 0 and 1.

Alice and Bob make alternating moves: Alice makes the first move, Bob makes the second move, Alice makes the third one, and so on. During each move, the current player must choose two different adjacent characters of string s and delete them. For example, if s=1011001 then the following moves are possible:

delete s1 and s2: 1011001→11001;
delete s2 and s3: 1011001→11001;
delete s4 and s5: 1011001→10101;
delete s6 and s7: 1011001→10110.
If a player can't make any move, they lose. Both players play optimally. You have to determine if Alice can win.

*/
#include<stack>
int main() {
	
	ll t;
	cin>>t;
	while(t--){
		ll i,j,k,l,n;
		string s;
		cin>>s;
		n = s.size();
		ll ch=0;
		stack<char> st;
		for(i=0;i<n;){
			if(!st.empty()){
				if(st.top()!=s[i])
				{
					st.pop();
					i++;
					ch++;
				}
				else{
					st.push(s[i++]);
				}
			}
			else
			st.push(s[i++]);
		}
		if(ch%2)
		cout<<"DA\n";
		else
		cout<<"NET\n";
	}
	
	// your code goes here
	return 0;
}