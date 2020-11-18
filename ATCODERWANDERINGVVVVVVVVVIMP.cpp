#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
	ll i,j,k,l,mx=0,ans=0,res=0,res2=0;
	for(i=1;i<n;i++)
	a[i]+=a[i-1];
	for(i=0;i<n;i++)
	{
		ans = max(ans,res+mx);
		res+=a[i];
		mx = max(mx,a[i]);
	}
	ans = max(res,ans);
	return ans;
}
int main() {
	
	ll j,k,l,i,n;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<solve(a,n);
	// your code goes here
	return 0;
}	
/*

Given is a number sequence 
A
1
,
A
2
,
A
3
,
…
,
A
N
, which may contain negative elements.
On a number line, there is a robot at coordinate 
0
. It will do the following actions in order:

Move 
A
1
 in the positive direction.
Move 
A
1
 in the positive direction, and then move 
A
2
 in the positive direction.
Move 
A
1
 in the positive direction, then move 
A
2
 in the positive direction, and then move 
A
3
 in the positive direction.
⋮

Move 
A
1
 in the positive direction, then move 
A
2
 in the positive direction, then move 
A
3
 in the positive direction, 
…
, 
…
, and then move 
A
N
 in the positive direction.
Find the greatest coordinate occupied by the robot from the beginning to the end of the process.


3
2 -1 -2


5




*/