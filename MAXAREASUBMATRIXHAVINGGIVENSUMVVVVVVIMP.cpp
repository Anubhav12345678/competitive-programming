#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
ll a[1005][1005];
ll dp[1005][1005];
ll n,m,th;
/*
Given a 2D Grid A[i][j] consisiting of n rows and m columns. 

You need to find a square submatrix of the matrix A such that the sum of its elements is at most x, and its area (the total number of elements) is the largest possible.

*/
void makedp(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
		}
	}
}
ll get(ll x1,ll y1,ll x2,ll y2){
	return dp[x2][y2] - dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}
ll getsum(ll enx,ll eny, ll len){
	ll stx = enx-len+1;
	ll sty = eny-len+1;
	return get(stx,sty,enx,eny);
}

ll ans(ll x,ll y){
	ll lo=1;
	ll hi=min(x,y);
	ll i,j,k,l,cell=0,mid;
	while(lo<=hi){
		mid= (lo+hi)/2;
		ll sum = getsum(x,y,mid);
		if(sum<=th)
		{
			cell = mid;
			lo=mid+1;
		}
		else
		hi=mid-1;
	}
	return cell;
}
int main(){

  ll i,j,k,l;
  cin>>n>>m>>th;

//   ll a[n][m];
  for(i=1;i<=n;i++){
	  for(j=1;j<=m;j++) cin>>a[i][j];
  }
  makedp();
  ll cell=0;
//   ll ans=0;
  for(i=1;i<=n;i++){
	  for(j=1;j<=m;j++){
		  cell = max(cell,ans(i,j));
	  }
  }
  cout<<cell*cell<<endl;
























	return 0;
}
























