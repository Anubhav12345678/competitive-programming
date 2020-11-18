#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#define se second
#define ff first
#define mp make_pair
#include<queue>
/*
Dexter was good in finding the K th smallest number from a set of numbers. He thought he could solve any problem related to K th smallest number. His friend Pipi challenged him with a problem.
He gave him various ranges of number, These numbers were arranged in increasing order(only distinct numbers to be taken into account). Now he asked him to find the K th smallest number in the sequence, again and again.

*/
bool comp(pair<ll,ll> a,pair<ll,ll> b){
	if(a.ff!=b.ff) return a.ff<b.ff;
	return a.se<b.se;
}
int main(){

   ll i,j,k,l,n,m,t,q,p;
   cin>>t;
   while(t--){
	   cin>>n>>q;
	//    priority_queue<pair<pair<ll,ll>, ll>> pq(n);
	vector<pair<ll,ll>> v;
	   for(i=0;i<n;i++) {
		   ll a,b;
		   cin>>a>>b;
		   v.pb({a,b});
	   }
      sort(v.begin(),v.end(),comp);
	  vector<pair<ll,ll>> ans;
	  ans.push_back(v[0]);
	  ll x=0;
	  for(i=1;i<v.size();i++){
		  if(v[i].ff<=ans[x].se){
			  ans[x].se = max(v[i].se,ans[x].se);
		  }
		  else{
			  ans.pb(v[i]);
			  x++;
		  }
	  }
	  vector<ll> arr(ans.size()+1);
	  arr[0]=0;
	  ll sum=0;
	  for(i=1;i<=ans.size();i++){
		  sum+=ans[i-1].se-ans[i-1].ff+1;
		  arr[i] =sum;
	  }
	  while(q--){
		  cin>>k;
		  for(i=0;i<ans.size();i++){
			  if(k>arr[i]&&k<=arr[i+1]){
				  ll r = k-arr[i];
				  cout<<ans[i].ff+r-1<<endl;
				  break;
			  }
		  }
		  if(i==ans.size())
		  cout<<"-1"<<endl;
	  }



   }











	return 0;
}




















