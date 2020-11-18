#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*
You are given three multisets of pairs of colored sticks:

R pairs of red sticks, the first pair has length r1, the second pair has length r2, …, the R-th pair has length rR;
G pairs of green sticks, the first pair has length g1, the second pair has length g2, …, the G-th pair has length gG;
B pairs of blue sticks, the first pair has length b1, the second pair has length b2, …, the B-th pair has length bB;
You are constructing rectangles from these pairs of sticks with the following process:

take a pair of sticks of one color;
take a pair of sticks of another color different from the first one;
add the area of the resulting rectangle to the total area.
Thus, you get such rectangles that their opposite sides are the same color and their adjacent sides are not the same color.

Each pair of sticks can be used at most once, some pairs can be left unused. You are not allowed to split a pair 
into independent sticks.

What is the maximum area you can achieve?
*/
ll ans=0;
vector<ll> ar;
vector<ll>  ag;
vector<ll> ab;
ll r,g,b;
ll dp[201][201][201];
ll solve(ll x,ll y,ll z){
	if((x>=r&&y>=g)||(x>=r&&z>=b)||(y>=g&&z>=b))
	return 0;
	if(dp[x][y][z]!=-1) return dp[x][y][z];
	ll maxi =0;
	if(x<r&&y<g)
	maxi = max(maxi,ar[x]*ag[y]+solve(x+1,y+1,z));
	if(y<g&&z<b)
	maxi = max(maxi,ag[y]*ab[z]+solve(x,y+1,z+1));
	if(x<r&&z<b)
	maxi = max(maxi,ar[x]*ab[z]+solve(x+1,y,z+1));
	ans = max(ans,maxi);
	return dp[x][y][z] =maxi;
}
int main() {
	ll i,j,k,l,n,t;
	cin>>r>>g>>b;
	// vector<ll> v1(r),v2(g) , v3(b);
	ar.resize(r);
	ag.resize(g);
	ab.resize(b);
	memset(dp,-1,sizeof(dp));
	for(i=0;i<r;i++) cin>>ar[i];
	for(i=0;i<g;i++) cin>>ag[i];
	for(i=0;i<b;i++) cin>>ab[i];
	sort(ar.begin(),ar.end(),greater<>());
	sort(ag.begin(),ag.end(),greater<>());
	sort(ab.begin(),ab.end(),greater<>());
	
	ans=0;
	solve(0,0,0);
	cout<<ans<<endl;
	// your code goes here
	return 0;
}