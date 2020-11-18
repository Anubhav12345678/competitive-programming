#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<limits.h>
#define e endl;
/*
problem can be stated as
Find the minimum number of insertions in the substring str[l+1,…….h].
2. Find the minimum number of insertions in the substring str[l…….h-1].
3. Find the minimum number of insertions in the substring str[l+1……h-1].



The minimum number of insertions in the string str[l…..h] can be given as:

minInsertions(str[l+1…..h-1]) if str[l] is equal to str[h]
min(minInsertions(str[l…..h-1]), minInsertions(str[l+1…..h])) + 1 otherwise

*/
ll mininsert(string s,ll l,ll h)
{
	if(l>h)
	return INT_MAX;
	if(l==h)
	return 0;
	if(l==h-1)
	return (s[l]==s[h])?0:1;
	if(s[l]==s[h])
	return mininsert(s,l+1,h-1);
	else
	return min(mininsert(s,l,h-1),mininsert(s,l+1,h))+1;//first make min no of insertions in the segment and then add one character for the last character remaining for making whole string palindrome
	
}
int main() {
	ll t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<mininsert(s,0,s.size()-1)<<e;
	}
	
	// your code goes here
	return 0;
}

//me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(string s)
{
	ll n=s.size();
	ll i,j,k,l,gap,h;
	ll tab[n][n];
	memset(tab,0,sizeof(tab));
	for(gap=0;gap<n;gap++)
	{
		for(l=0,h=gap;h<n;++l,++h)
		{
			tab[l][h] = (s[l]==s[h])?(tab[l+1][h-1]):(min(tab[l+1][h],tab[l][h-1])+1);
		}
	}
	return tab[0][n-1];
	
}
int main() {
	cout<<solve("geeks")<<endl;
	// your code goes here
	return 0;
}