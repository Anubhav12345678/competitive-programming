
/*
You are given an array a of length n consisting of zeros. You perform n actions with this array:
 during the i-th action, the following sequence of operations appears:

Choose the maximum by length subarray (continuous subsegment) consisting only of zeros, among all
 such segments choose the leftmost one;
Let this segment be [l;r]. If r−l+1 is odd (not divisible by 2) then assign (set) a[l+r2]:=i (where
 i is the number of the current action), otherwise (if r−l+1 is even) assign (set) a[l+r−12]:=i.
Consider the array a of length 5 (initially a=[0,0,0,0,0]). Then it changes as follows:

Firstly, we choose the segment [1;5] and assign a[3]:=1, so a becomes [0,0,1,0,0];
then we choose the segment [1;2] and assign a[1]:=2, so a becomes [2,0,1,0,0];
then we choose the segment [4;5] and assign a[4]:=3, so a becomes [2,0,1,3,0];
then we choose the segment [2;2] and assign a[2]:=4, so a becomes [2,4,1,3,0];
and at last we choose the segment [5;5] and assign a[5]:=5, so a becomes [2,4,1,3,5].
Your task is to find the array a of length n after performing all n actions. Note that the answer exists and unique.

You have to answer t independent test cases.

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<queue>
#define fi first
#define se second
void solve(ll n)
{
	ll i,j,k,l,r;
	vector<ll> res(n);
	ll cnt=0LL;
	priority_queue<pair<ll,pair<ll,ll>>> pq;
	pq.push({n,{0,n-1}});
	while(!pq.empty())
	{
		l = -1*pq.top().se.fi;
		r = pq.top().se.se;
		ll len = pq.top().fi;
		pq.pop();
		if(l>r) continue;
		cnt++;
		ll m = (l+r)/2;
		res[m]=cnt;
		pq.push({m-l+1,{-1*l,m-1}});  // minus b4 l so that if same size leftmost subarray is considered
		pq.push({r-m+1,{-1*(m+1),r}});
	}
	for(i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;
	
}
int main() {
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		solve(n);
	}
	// your code goes here
	return 0;
}