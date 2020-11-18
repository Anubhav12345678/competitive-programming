#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
/*
Given N integers and K, find the minimum number of elements that should be removed such that Amax-Amin<=K. After removal of elements, Amax and Amin is considered among the remaining elements. 
Examples: 
 

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5 


*/
ll  find(ll key,ll k,ll i,ll n, ll a[])
{
	ll st=i+1;
	ll en = n-1;
	ll ind=-1;
	while(st<en)
	{
		ll mid = st+(en-st)/2;
		if((a[mid]-key)<=k)
		{
			ind=mid;
			st=mid+1;
		}
		else
		en=mid;
		
	}
	return ind;
}
int main() {
	ll i,j,k,l,n;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++) cin>>a[i];
	cin>>k;
	sort(a,a+n);
	ll ans=n-1;
	for(i=0;i<n;i++)
	{
		j=find(a[i],k,i,n,a);
		if(j!=-1)
		{
			ans = min(ans,n-(j-i+1));
		}
	}
	cout<<ans<<endl;
	// your code goes here
	return 0;
}