#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll x,i,j,n,t;
	cin>>t;
	while(t--)
	{
		ll nod1=0,nod2=0,s=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x%2)
			nod1++;
			s+=x;
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x%2)
			nod2++;
			s+=x;
		}
		ll diff = abs(nod1-nod2);
		s = s-diff;
		cout<<s/2<<endl;
	}
	
	// your code goes here
	return 0;
}