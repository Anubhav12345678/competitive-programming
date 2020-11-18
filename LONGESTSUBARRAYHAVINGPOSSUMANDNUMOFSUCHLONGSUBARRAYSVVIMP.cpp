#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
const ll maxn = 1000005;
/*
This time your task is simple.

Task:
Mehta has to find the longest subarray whose sum is greater than equal to zero in a given array of length** N**. After he finds4
 out the length of longest subarray, he has to report how many subarrays of such maximum length exist that satisfy the mentioned
  property.
*/
ll a[maxn],n;
bool ok(ll m){
	if(a[m-1]>=0) return 1;
	for(ll i=1;i<n-m+1;i++)
	if(a[i+m-1]>=a[i-1]) return 1;
	return 0;
}
int main(){
 ll i,j,k,l,m;
 cin>>n;
//  ll a[n+1];
//  a[0]=0;
cin>>a[0];
 for(i=1;i<n;i++) {
	 cin>>a[i];
	 a[i]+=a[i-1];
 }
 ll lo=1;
 ll hi=n;
 ll ans=-1;
 while(lo<=hi){
	 ll mid = (lo+hi)/2;
	 if(ok(mid))
	 {
		 ans = mid;
		 lo=mid+1;
	 }
	 else
	 hi=mid-1;
 }
 if(ans==-1){
	 cout<<"-1"<<endl;
 }
 else{
	 ll cnt=0;
	 if(a[ans-1]>=0) cnt++;
	 for(i=1;i<n-ans+1;i++)
	 {
		 if(a[i+ans-1]>=a[i-1]) cnt++;
	 }
	 cout<<ans<<" "<<cnt;
 }
	
}

























