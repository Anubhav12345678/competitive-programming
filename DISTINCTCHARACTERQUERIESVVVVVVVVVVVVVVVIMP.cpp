#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*

You are given a string s consisting of lowercase Latin letters and q queries for this string.

Recall that the substring s[l;r] of the string s is the string slsl+1…sr. For example, the substrings 
of "codeforces" are "code", "force", "f", "for", but not "coder" and "top".

There are two types of queries:

1 pos c (1≤pos≤|s|, c is lowercase Latin letter): replace spos with c (set spos:=c);
2 l r (1≤l≤r≤|s|): calculate the number of distinct characters in the substring s[l;r].


*/
#include<set>
int main() {
	int i,j,k,l,n,t,q,r;
	string s;
	cin>>s>>q;
	vector<set<int>> vec(26);
	n=s.size();
	for(i=0;i<n;i++)
	{
		vec[s[i]-'a'].insert(i);
	}
	// for(i=0;i<n;i++)
	// {
	// 	for(auto  it=vec[i].begin();it!=vec[i].end();it++)
	// 	cout<<*it<<" ";
	// 	cout<<endl;
	// }
	while(q--)
	{
		cin>>k;
		if(k==1)
		{
			char c;
			cin>>r>>c;
			r--;
			vec[s[r]-'a'].erase(r);
			s[r]=c;
			vec[s[r]-'a'].insert(r);
		}
		else
		{
			cin>>l>>r;
			l--;
			r--;
			int res=0;
			for(int p=0;p<26;p++)
			{
				auto it = vec[p].lower_bound(l);
				if(it!=vec[p].end()&&(*it)<=r)
				res++;
			}
			cout<<res<<endl;
		}
	}
	// your code goes here
	return 0;
}