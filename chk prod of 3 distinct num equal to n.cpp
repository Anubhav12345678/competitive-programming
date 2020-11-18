// chk prod of 3 distinct num equal to n
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t,i,j,k,l,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a[3]={0};
		ll ct=0;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				a[ct++] = i;
				n=n/i;
				if(ct==2)
				break;
			}
		}
		a[2]=n;
		if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]!=a[0]&&a[0]>=2&&a[1]>=2&&a[2]>=2)
		{
			cout<<"YES\n";
			cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
			continue;
		}
		cout<<"NO\n";
		
	}
	// your code goes here
	return 0;
}