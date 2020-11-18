 
#include <bits/stdc++.h>
using namespace std;
int v[100005];
#define ll int64_t
/*
Little Black Panda is mad about XOR operation. Presently he has gone mad and he won't stop performing XOR operation
 on various numbers.
Given an array of N numbers, for each subset of the array Little Panda performs MAXOR operation for the subset. MAXOR 
operation means that he finds XOR of all elements in that subset (if the subset is [1,2,3] then MAXOR is 1^2^3=0) . 
Little Panda is now exhausted and wants to do something else. Little Panda wants to pick any two subsets the MAXOR 
of whose are same. Little Panda needs to find the number of selections that he can make. He is very very weak in 
programming so he wants the answer from you. Please help little panda in finding out his query.
Since the output can be very large output it modulo 1000000007.

*/
#define hell 1000000007
int main() 
{
	int num; cin>>num;
	for(int i=0;i<num;i++) cin>>v[i];
 
	vector<ll>dp(128,0);
 
	dp[0]=1;
 
	for(int i=0;i<num;i++)
	{
       vector<ll>temp=dp;
	   for(int j=0;j<128;j++)
	   {
		temp[(j^v[i])]=(temp[(j^v[i])]+dp[j])%hell;
	   }
	   dp=temp;
	}
	ll ans=0;
	dp[0]--;
	for(int i=0;i<128;i++)
	{
		ans=(ans+(((dp[i]*(dp[i]-1))/(ll(2)))%hell)%hell)%hell;
	}
    cout<<ans<<endl;
	return 0; 
} 
 