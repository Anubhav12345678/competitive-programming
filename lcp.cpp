#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<limits.h>
void lcp(string arr[],ll n)
{
	ll mini = INT_MAX;
// 	string prefix="";
	ll i,j;
	string s = arr[0];
	ll len1 = s.size();
// 	ll p[n];
	for(i=0;i<n;i++)
	p[i]=0;
	for(i=1;i<n;i++)
	{
		ll len = arr[i].size();
		for(j=0;j<min(len,len1);j++)
		if(arr[i][j]!=s[j])
		break;
// 		p[i] = j;
		mini =  min(mini,j);
	}
	// if(mini==0)
	// return 0;
	// return mini+1;
	for(i=0;i<mini;i++)
	cout<<s[i];
	cout<<endl;
	
}
int main() {
	ll t,n;
	cin>>t;
	string arr[1001];
	while(t--)
	{
		cin>>n;
// 		string arr[n];
		for(ll i=0;i<n;i++)
		cin>>arr[i];
	    lcp(arr,n);
	}
	// your code goes here
	return 0;
}