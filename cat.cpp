#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define VI vector<ll>
int main() {
	VI idx = {0, 1, 2, 0, 2, 1, 0};
	VI a(3);
	cin>>a[0]>>a[1]>>a[2];
	ll full = min(min(a[0]/3,a[1]/2),a[2]/2);
	a[0]-=full*3;
	a[1]-=full*2;
	a[2]-=full*2;
	ll st=0;
	ll ans=0;
	for(;st<7;st++)
	{
			ll cur=0;
		ll d = st;
			VI b=a;
		while(b[idx[d]]>0)
		{
			--b[idx[d]];
			d = (d+1)%7;
			cur++;
		}
		ans = max(ans,cur+full*7);
	}
	cout<<ans<<endl;
	
	// your code goes here
	return 0;
}