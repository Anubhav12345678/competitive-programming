#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n,d,a[100005],i,j,s=0,t;
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>n>>d;
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		for(i=n-1;i>0;i--)//as sum ki maxvalue chahiye isliye backwards trace kiya
		if((a[i]-a[i-1])<d)
		{
			s+=a[i]+a[i-1];
			i--;
		}
		cout<<s<<endl;
	}
	// your code goes here
	return 0;
}