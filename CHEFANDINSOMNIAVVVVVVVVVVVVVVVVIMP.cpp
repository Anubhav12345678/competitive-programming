#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
// #define maxa 100100
/*
Chef sometimes suffers from insomnia. During sleepless nights, he often plays this game: 
He creates an array A of N integers and also decides one integer K. After that, he tries to
 count the number of non-empty contiguous subsequences (subsegments) of A, such that there
  are no bad pairs of integers in this subsegment. A pair (x, y) of integers is called bad
   if x is situated to the left of y in the array and x mod y = K. Finally, before going to
    sleep, Chef wrote down the answer on a sheet of paper. Sadly, he has forgotten it this morning and want your help regarding that.



*/
ll solve(vector<ll> &A,ll K){
	ll i,j,k,l,n=A.size();
	vector<ll> cnt(100100,-1);
 ll	maxa = *max_element(A.begin(),A.end());
	ll ans=0,maxi=-1;
	for(i=0;i<n;i++)
	{
		if(K<A[i]){
			for(j=K;j<=maxa;j+=A[i])
			{
				if(cnt[j]!=-1)
				maxi = max(maxi,cnt[j]);
			}
		}
		ans+=(i-maxi);
		cnt[A[i]]=i;
	}
	return ans;
}
int main() {
	ll i,j,k,l,n;
	cin>>n>>k;
	vector<ll> v(n);
	
	for(i=0;i<n;i++) cin>>v[i];
	cout<<solve(v,k)<<endl;
	
	// your code goes here
	return 0;
}