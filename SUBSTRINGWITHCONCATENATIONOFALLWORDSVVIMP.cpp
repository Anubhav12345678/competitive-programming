#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define ll long long
//SUBSTRING WITH CONCAT OF ALL WORDS
vector<int> solve(vector<string> list,string s)
{
	vector<int> res;
	if(s.size()==0||list.size()==0)
	return res;
	int i,j,k,l,a,b,c,n,m;
	n = list.size();
	m = list[0].size();
	int ts = n*m;
	if(ts>s.size())
	return res;
	map<string,int> m1;
	for(i=0;i<n;i++)
	m1[list[i]]++;
	for(i=0;i<=s.size()-ts;i++)
	{
		map<string,int> tmp(m1);
		j=i;
		int cnt=n;
		while(j<i+ts)
		{
			string p = s.substr(j,m);
			if(m1.find(p)==m1.end()||tmp[p]==0)
			break;
			else
			{	
				tmp[p]--;
				cnt--;
			}
			j+=m;
		}
		if(cnt==0)
		res.pb(i);
	}
	return res;
}
int main() {
	int i,j,k,l,n;
	cin>>n;
	vector<string> list(n);
	for(i=0;i<n;i++)
	cin>>list[i];
	string s;
	cin>>s;
	vector<int> v = solve(list,s);
	if(v.size()==0)
	{
		cout<<"result is empty!!!";
		return 0;
	}
	for(i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	// your code goes here
	return 0;
}