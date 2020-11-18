#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
You are playing one RPG from the 2010s. You are planning to raise your smithing skill, so you need as many resources as 
possible. So how to get resources? By stealing, of course.

You decided to rob a town's blacksmith and you take a follower with you. You can carry at most p units and your follower —
 at most f units.

In the blacksmith shop, you found cnts swords and cntw war axes. Each sword weights s units and each war axe — w units.
 You don't care what to take, since each of them will melt into one steel ingot.

What is the maximum number of weapons (both swords and war axes) you and your follower can carry out from the shop?
*/
ll solve(ll p,ll f,ll cnts,ll cntw,ll s,ll w){
	if(s>w)
	{
		swap(s,w);
		swap(cnts,cntw);
	}
	
	ll ans=0;
	for(ll i=0;i<=cnts;i++){
		if((i*s)>p) continue;
		ll x =i;
		ll y = min(cnts-i,f/s);
		ll lefts = p-x*s;
		ll leftw = f-y*s;
		ll w1 = min(lefts/w,cntw);
		ll w2 = min(leftw/w,cntw-w1);
		ans   = max(ans,x+y+w1+w2);
	}
	return ans;
}
int main() {
	
	ll t,i,j,k,l;
	cin>>t;
	while(t--){
		ll p,f,cnts,cntw,s,w;
		cin>>p>>f>>cnts>>cntw>>s>>w;
		cout<<solve(p,f,cnts,cntw,s,w)<<endl;
	}
	// your code goes here
	return 0;
}