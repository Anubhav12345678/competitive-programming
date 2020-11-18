#include <bits/stdc++.h>
using namespace std;
#define ll long long
// FREQUENCYOFANYCHARACTERINANYRANGEOFASTRINGVVIMP
ll solve(char character,string s,ll l,ll r)
{
	ll n=s.size();
	ll i,j,k;
	ll h[n][26];
	memset(h,0,sizeof(h));
	h[0][s[0]-'a']++;
	for(i=1;i<n;i++)
	{
		char c = s[i];
		// cout<<"s["<<i<<"] = "<<s[i]<<" c = "<<c<<endl;
		h[i][c-'a'] = h[i-1][c-'a']+1;
		for(j=0;j<26;j++)
		{
			char ch = (char)(j+'a');
			if(ch!=c)
			{
				h[i][ch-'a']=h[i-1][ch-'a'];
			}
		}
	}
	return h[r][character-'a']-h[l-1][character-'a'];
}
int main() {
   string s="aabbbbcaacjkl";
   cout<<solve('b',s,2,6);
   
   ll l,r,i,j,k;
	
	
	// your code goes here
	return 0;
}