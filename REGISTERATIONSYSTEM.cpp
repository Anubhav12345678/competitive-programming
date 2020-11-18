#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<set>
#include<map>
int main() {
	int n;
	set<string> s;
	cin>>n;
	map<string,int> m;
	while(n--)
	{
		string st;
		cin>>st;
		if(s.find(st)==s.end())
		{
			cout<<"OK\n";
			s.insert(st);
			m[st]++;
			continue;
		}
		cout<<st<<m[st]<<endl;
		m[st]++;
		// s.insert(st);
	}
	// your code goes here
	return 0;
}