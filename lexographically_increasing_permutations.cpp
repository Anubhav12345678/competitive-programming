#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back
// lexographically increasing permutations of a given string
ll fact(ll n)
{
	if(n==0)
	return 1;
	return n*fact(n-1);
}
void swap(char *x,char *y)
{
	char t = *x;
	*x = *y;
	*y = t;
}
void permute(char *a,int l,int r)
{
	if(l==r)
	{
		cout<<a<<" ";
	}
	else
	{
		int i;
		for(i=l;i<=r;i++)
		{
			swap((a+l),(a+i));
			permute(a,l+1,r);
			swap((a+l),(a+i));
		}
	}
}

int main()
{
	ll t;
	char s[100001];
	cin>>t;
	while(t--)
	{
		cin>>s;
		int n = strlen(s);
		permute(s,0,n-1);
	}
}