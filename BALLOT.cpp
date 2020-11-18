#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  #endif
  

  ll i,j,k,l,n,b,h,m;
  cin>>n>>b;
  ll a[n],s=0;
  for(i=0;i<n;i++) 
  	{
  		cin>>a[i];
  		s+=a[i];
  	}
  	// cout<<s<<endl;
  l=0,h=s;
  while(l<h)
  {
  	m = l+(h-l)/2;
  	if((m*b)<=s)
  		l=m+1;
  	else
  		h=m-1;
  }
  cout<<l<<endl;
}
