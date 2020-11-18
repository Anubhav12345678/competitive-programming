#include<bits/stdc++.h>
using namespace std;
#define ll long long
 /*
This is the hard version of the problem. The difference between the versions is the constraint on n and the required number 
of operations. You can make hacks only if all versions of the problem are solved.

There are two binary strings a and b of length n (a binary string is a string consisting of symbols 0 and 1). In an operation,
 you select a prefix of a, and simultaneously invert the bits in the prefix (0 changes to 1 and 1 changes to 0) and reverse the 
 order of the bits in the prefix.

For example, if a=001011 and you select the prefix of length 3, it becomes 011011. Then if you select the entire string, it 
becomes 001001.

Your task is to transform the string a into b in at most 2n operations. It can be proved that it is always possible.

 */
	void solve(){
		int n; cin>>n;
		string s,t; cin>>s>>t;
		s+='0'; 
		t+='0';
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s[i+1])
			{
				a.push_back(i+1);
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(t[i]!=t[i+1])
			{
				a.push_back(i+1);
			}
		}
		cout<<a.size()<<' ';
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<"\n";
		return; 
}
int main()
{
ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
while(t--)
{
solve();
}
return 0;
}