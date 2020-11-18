#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#define e endl
#include<map>
#define f first
#define s second
int main() {
	ll q,type,i,marks;
	map<string, int> m;
	map<string, int>::iterator it,itr;
	string s;
	cin>>q;
	while(q--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>s;
			cin>>marks;
			m[s]  = m[s] + marks;
		}
		if(type==2)
		{
			cin>>s;
			m.erase(s);
		}
		if(type==3)
		{
			cin>>s;
			// cout<<m[s]<<e;
			itr = m.find(s);//complexity log(n)
			if(itr==m.end())
			cout<<0<<endl;
			else
			cout<<m[s]<<endl;
			
		}
	}
	// your code goes here
	return 0;
}