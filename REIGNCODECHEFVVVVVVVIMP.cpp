#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll lo[100005];
ll ri[100005];
int main() {
	ll i,j,k,l,n,m;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++) cin>>a[i];
		ll maxso,maxen;
		maxso=maxen=lo[0] = a[0];
		for(i=1;i<n;i++)
		{
			maxen = max(a[i],a[i]+maxen);
			maxso = max(maxso,maxen);
			lo[i] = maxso;
		}
		maxso = maxen =ri[n-1] =  a[n-1];
		for(i=n-2;i>=0;i--)
		{
			maxen= max(a[i],maxen+a[i]);
			maxso = max(maxso,maxen);
			ri[i] = maxso;
		}
		ll ans=0;
		ans = lo[0]+ri[k+1];
		for(i=1LL;i<n-k-1;i++)
		{
			ans= max(ans,lo[i]+ri[i+k+1]);
		}
		cout<<ans<<endl;
	}
	// your code goes here
	return 0;
}