// There is a frog staying to the left of the string s=s1s2…sn consisting of n characters (to be more precise, the frog initially stays at the cell 0). Each character of s is either 'L' or 'R'. It means that if the frog is staying at the i-th cell and the i-th character is 'L', the frog can jump only to the left. If the frog is staying at the i-th cell and the i-th character is 'R', the frog can jump only to the right. The frog can jump only to the right from the cell 0.

// Note that the frog can jump into the same cell twice and can perform as many jumps as it needs.

// The frog wants to reach the n+1-th cell. The frog chooses some positive integer value d before the first jump (and cannot change it later) and jumps by no more than d cells at once. I.e. if the i-th character is 'L' then the frog can jump to any cell in a range [max(0,i−d);i−1], and if the i-th character is 'R' then the frog can jump to any cell in a range [i+1;min(n+1;i+d)].

// The frog doesn't want to jump far, so your task is to find the minimum possible value of d such that the frog can reach the cell n+1 from the cell 0 if it can jump by no more than d cells at once. It is guaranteed that it is always possible to reach n+1 from 0.

// You have to answer t independent test cases.


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
ll solve(string s)
{
	ll i,j,k,l,n=s.size();
	vector<ll> pos;
	pos.pb(0);
	for(i=0;i<n;i++)
	if(s[i]=='R') pos.pb(i+1);
	pos.pb(n+1);
	ll ans=0;
	for(i=0;i<pos.size()-1;i++)
	ans = max(ans,pos[i+1]-pos[i]);
	return ans;
}
int main() {
	ll t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<solve(s)<<endl;
	}
	// your code goes here
	return 0;
}