#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#include<set>
#include<iterator>
#include<string.h>
int main() {
	ll n,t,k,x,y;
	char s3[201];
	char s[] = "CLICK";
	char s2[] = "CLOSEALL";
	set<ll> sa;
	set<ll>::iterator it;
	cin>>n>>k;
	while(k--)
	{
		cin>>s3;
		if(strcmp(s3,s)==0)
		{
			cin>>x;
			if(sa.find(x)==sa.end())
			sa.insert(x);
			else
			sa.erase(x);
		}
		else if(strcmp(s3,s2)==0)
		{
			sa.clear();
		}
		cout<<sa.size()<<endl;
	}
	// your code goes here
	return 0;
}