#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define pb push_back
#include<map>
const int maxn = 1000005;
/*
Acfreak was working on a tree problem which he finds hard to solve. So he called upon you to help
 him out to solve the task. You are given an undirected weighted tree rooted at 1. You need to count 
 the number of distinct paths from the root to leaves such that the XOR-Value of the weights in the path is odd. 


*/
vector<int> v[maxn];
int ans;
map<pair<int,int>,int> mp;
void fun(int k,int par,int x){
	int d=0;
	for(auto y:v[k]){
		if(y!=par){
			d=1;
			fun(y,k,x^mp[{k,y}]);
		}
	}

	if(d==0&&x%2==1) // resulting leaf and x denotes xor uptill it
	ans++;
}
int main(){
  int i,j,k,l,n,m,t;
  cin>>t;
  while(t--){
	  mp.clear();
	//   v.clear();
	  ans=0;
	  cin>>n;
	  for(i=1;i<=n;i++) v[i].clear();
	  for(i=0;i<n-1;i++){
		  int a,b,c;
		  cin>>a>>b>>c;
		  mp.insert({{a,b},c});
		  mp.insert({{b,a},c});
		  v[a].pb(b);
		  v[b].pb(a);
	  }

	  fun(1,0,0);
	  cout<<ans<<endl;
  }



























	return 0;
}



























