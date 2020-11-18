#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10004][102];
int main(){


    ll t,i,j,k,l,n,x;
	ll mod=1e9+7;
    cin>>t;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=100;i++) dp[0][i]=1;
	for(k=1;k<=100;k++){
		for(i=1;i<=10000;i++){
			for(j=1;j<=min(i,k);j++)
			{
				dp[i][k]+=dp[i-j][k];
				dp[i][k]%=mod;
			}
		}
	}
	while(t--){
		cin>>x>>k;
		cout<<dp[x][k]%mod<<endl;
	}



/*
HP is standing at a distance of X kilometres from her house . She can travel at most K kilometres in a single step. 
She wants to know total number of ways to reach her house . As the number of ways can be large , print it modulo 1e9+7.
*/








	return 0;
}