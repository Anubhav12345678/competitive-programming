#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t,i,j,k,l,n,m,K,q,p;
	cin>>t;
	while(t--){
		cin>>n>>K;
		ll dp[1001], f[1001], cnt[101];
		for(i=0;i<n;i++) cin>>f[i];
		for(i=0;i<1001;i++) dp[i] = 1e9;
		dp[0]=0;
		for(i=0;i<n;i++){
			memset(cnt,0,sizeof(cnt));
			for(j=i;j<n;j++){
				cnt[f[j]]++;
				ll g=0;
				for(k=1;k<=100;k++)
				if(cnt[k]!=1) g+=cnt[k];
				dp[j+1] = min(dp[i]+g+K,dp[j+1]);
			}
		}
		
		cout<<dp[n]<<endl;
	}
	// your code goes here
	return 0;
}
/*
There are N guests (numbered 1 through N) coming to Chef's wedding. Each guest is part of a family; for each valid i
, the i-th guest is part of family Fi. You need to help Chef find an optimal seating arrangement.

Chef may buy a number of tables, which are large enough for any number of guests, but the people sitting at each table
 must have consecutive numbers ― for any two guests i and j (i<j) sitting at the same table, guests i+1,i+2,…,j−1 must
  also sit at that table. Chef would have liked to seat all guests at a single table; however, he noticed that two guests 
  i and j are likely to get into an argument if Fi=Fj and they are sitting at the same table.

Each table costs K rupees. Chef defines the inefficiency of a seating arrangement as the total cost of tables plus the number
 of guests who are likely to get into an argument with another guest. Tell Chef the minimum possible inefficiency which he can achieve.


*/