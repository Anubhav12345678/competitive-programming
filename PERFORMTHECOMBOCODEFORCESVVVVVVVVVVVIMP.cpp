#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

You want to perform the combo on your opponent in one popular fighting game. The combo is the string s consisting of n lowercase Latin letters. To perform the combo, you have to press all buttons in the order they appear in s. I.e. if s="abca" then you have to press 'a', then 'b', 'c' and 'a' again.

You know that you will spend m wrong tries to perform the combo and during the i-th try you will make a mistake right after pi-th button (1≤pi<n) (i.e. you will press first pi buttons right and start performing the combo from the beginning). It is guaranteed that during the m+1-th try you press all buttons right and finally perform the combo.

I.e. if s="abca", m=2 and p=[1,3] then the sequence of pressed buttons will be 'a' (here you're making a mistake and start performing the combo from the beginning), 'a', 'b', 'c', (here you're making a mistake and start performing the combo from the beginning), 'a' (note that at this point you will not perform the combo because of the mistake), 'b', 'c', 'a'.

Your task is to calculate for each button (letter) the number of times you'll press it.

You have to answer t independent test cases.


*/
// void solve(string s,
int main() {
	ll i,j,k,l,n,t,q,m;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>s;
		vector<ll> v(n,0);
		for(i=0;i<m;i++)
		{
			ll x;
			cin>>x;
			x--;
			v[0]++;
			v[x+1]--;
		}
		// for(i=0;i<n;i++) cout<<v[i]<<" ";
		// cout<<endl;
		for(i=1;i<n;i++)
		v[i]+=v[i-1];
		// for(i=0;i<n;i++) cout<<v[i]<<" ";
		// cout<<endl;
		for(i=0;i<n;i++)
		v[i]++;
		// for(i=0;i<n;i++) cout<<v[i]<<" ";
		// cout<<endl;
		vector<int> ans(26,0);
		for(i=0;i<n;i++)
		ans[s[i]-'a']+=v[i];
		for(i=0;i<26;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
		
		
		
	}
	// your code goes here
	return 0;
}