#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
// const ll maxn=1005;
ll solve(vector<ll> &v,ll K,ll m){
	ll i,j,k,l,n=v.size(),ans=0LL;
	vector<vector<ll>> dp(K+1,vector<ll>(n+1));

	// dp[j][i] represents max sum selecting j elements from i elements
	for(j=0;j<=K;j++){
		if(j==0 ) continue;
		else{
			for(i=0;i<n;i++)
			{
				if(j>((i+1)))
				dp[j][i] = -1e9;
				else
				{
					if(i==0) dp[j][i]=v[i];
					else
				dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]+v[i]*(j%m));
				}
			}
		}
	}
	return dp[K][n-1];
}

int main()
{
	ll i,j,k,l,n,m;
	cin>>n>>k>>m;
	vector<ll> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	cout<<solve(v,k,m)<<endl;
	return 0;

}
/*
We are given N numbers. We have to select K of them. We also have a number M. Suppose the numbers we selected were A1, A2, A3.. Ak. 
(note that we write these numbers in order in which they appeared in the original array). Define S = sum(Ai*(i%M)) for i=1 to i=K.
We have to maximize S.

Constraints : 

 
 
 
 
Input Format : 

 In the first line, three space separated integers  are given. In the next line,  space separated integers  are given.

*/


















