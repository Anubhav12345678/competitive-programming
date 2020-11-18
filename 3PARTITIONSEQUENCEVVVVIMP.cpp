#include<bits/stdc++.h>
using namespace std;
bool solve(int a[],int n,int k,int l,int m,map<string,bool> &lookup)
{
	if(n<0)
	return false;
	if(k==0&&l==0&&m==0)
	return 1;
	string key = to_string(k)+"|"+to_string(l)+"|"+to_string(m)+"|"+to_string(n);
	if(lookup.find(key)!=lookup.end())
	{
	    bool A=0,B=0,C=0;
	   if(k-a[n]>=0)
	   A = solve(a,n-1,k-a[n],l,m,lookup);
	   if(l-a[n]>=0)
	   B = solve(a,n-1,k,l-a[n],m,lookup);
	   if(m-a[n]>=0)
	   C = solve(a,n-1,k,l,m-a[n],lookup);
       lookup[key]  = A||B||C;
	}
	return lookup[key];
}
int main()
{
	// is it possible to divide the sequence into 3 non interesecting subsets equal sum
	int i,j,k,l,s=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	 cin>>a[i];
	 s+=a[i];
	}
	if(s%3)
	cout<<"Not possible";
	int k=s/3,l=s/3,m=s/3;
	map<string,bool > lookup;
	if(solve(a,n-1,k,l,m,lookup))
	cout<<"POssible\n";
	else
	cout<<"Not possible";
}