#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
/*
The array a=[a1,a2,…,an] (1≤ai≤n) is given. Its element ai is called special if there exists a pair of indices
 l and r (1≤l<r≤n) such that ai=al+al+1+…+ar. In other words, an element is called special if it can be represented 
 as the sum of two or more consecutive elements of an array (no matter if they are special or not).

Print the number of special elements of the given array a.

For example, if n=9 and a=[3,1,4,1,5,9,2,6,5], then the answer is 5:

a3=4 is a special element, since a3=4=a1+a2=3+1;
a5=5 is a special element, since a5=5=a2+a3=1+4;
a6=9 is a special element, since a6=9=a1+a2+a3+a4=3+1+4+1;
a8=6 is a special element, since a8=6=a2+a3+a4=1+4+1;
a9=5 is a special element, since a9=5=a2+a3=1+4.
Please note that some of the elements of the array a may be equal — if several elements are equal and special,
 then all of them should be counted in the answer.


*/
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		ll ans=0;
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		bool b[8008];
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			ll x=a[i];
			for(j=i+1;j<n;j++)
			{
				x+=a[j];
				if(x>n)
				break;
				b[x]=1;
			}
		}
		for(i=0;i<n;i++)
		ans+=b[a[i]];
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}