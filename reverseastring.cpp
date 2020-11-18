#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
int main() {
	string s,res,w;
	ll i,j;
	getline(cin,s);
	// cout<<s.size()<<endl;
	for(i=s.size()-1;i>=0;i--)
	{
		if(s[i]!=' '&&i<s.size())
		{
			// cout<<"w = "<<w<<endl;
			// cout<<"i = "<<i<<" s["<<i<<"] = "<<s[i]<<endl;
			while(s[i]!=' '&&i<s.size())
			{
				// cout<<"i = "<<i<<endl;
			w+=s[i];
			// cout<<"w = "<<w<<endl;
			i--;
				// cout<<"i = "<<i<<endl;
			}
			if(i==s.size())
			break;
			reverse(w.begin(),w.end());
			// cout<<"w = "<<w<<endl;
			// cout<<"res = "<<res<<endl;
			res+=w;
			// cout<<"res = "<<res<<endl;
			char c = ' ';
			res+=c;
			// cout<<"res = "<<res<<endl;
			w.clear();
			// cout<<"w = "<<w<<endl;
		}
	}
	cout<<res<<endl;
	// your code goes here
	return 0;
}