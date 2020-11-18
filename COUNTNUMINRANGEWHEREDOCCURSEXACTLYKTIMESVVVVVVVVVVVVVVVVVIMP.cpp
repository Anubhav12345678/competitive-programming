#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#define M 20 //as number can be max 10^18
ll dp[M][M][2][2];
ll d,K;
ll count(ll pos,ll cnt,ll tight,ll nonz,vector<ll> &v){
	if(pos==v.size()){
	    if(cnt==K)
	    return 1;
	    return 0;
	}
	
	if(dp[pos][cnt][tight][nonz]!=-1)
	return dp[pos][cnt][tight][nonz];
	
	ll ans=0;
	ll lim = (tight)?9:v[pos];
	for(ll dig = 0;dig<=lim;dig++){
		ll curcnt = cnt;
		if(dig==d){
			if(d!=0||(!d&&nonz)) curcnt++;
		}
		
		ll curtight =  tight;
		if(dig<v[pos])
		curtight=1;
		
		ans+=count(pos+1,curcnt,curtight,nonz||dig!=0,v);
	}
	
	return dp[pos][cnt][tight][nonz]=ans;
	
	
}
ll solve(ll x){
	vector<ll> v;
	while(x>0){
		v.pb(x%10);
		x/=10;
	}
	memset(dp,-1,sizeof(dp));
	reverse(v.begin(),v.end());
	return count(0,0,0,0,v);
}
int main() {
	
	ll L = 11, R = 100; 
    d = 2, K = 1; 
    cout << solve(R) - solve(L - 1) << endl; 
  
    return 0; 
	// your code goes here
	return 0;
}