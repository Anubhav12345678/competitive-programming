#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<map>
#define ff first
#define se second
ll solve(vector<ll> &v){
	ll i,j,k,l,n=v.size();
	map<ll,ll> mp;
	for(i=0;i<n;i++) mp[v[i]]++;
	ll ans=0;
	for(i=2;i<=101;i++){
		bool vis[101];
		memset(vis,0,sizeof(vis));
		ll tmp=0;
		for(auto it=mp.begin();it!=mp.end();it++){
			if(vis[it->ff]) continue;
			vis[it->ff]=true;
			ll x = i-it->ff;
			if(x==it->ff) tmp+=(it->se)/2;
			else if(mp.find(x)!=mp.end()){
				vis[x]=true;
				tmp+=min(it->se,mp[x]);
			}
		}
		ans  =max(ans,tmp);
	}
	return ans;
}
int main()
{
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++ ) cin>>v[i];
		cout<<solve(v)<<endl;
	}
	
	
	return 0;
}


/*
There are n people who want to participate in a boat competition. The weight of the i-th participant
 is wi. Only teams consisting of two people can participate in this competition. As an organizer, you 
 think that it's fair to allow only teams with the same total weight.

So, if there are k teams (a1,b1), (a2,b2), …, (ak,bk), where ai is the weight of the first participant 
of the i-th team and bi is the weight of the second participant of the i-th team, then the condition
 a1+b1=a2+b2=⋯=ak+bk=s, where s is the total weight of each team, should be satisfied.

Your task is to choose such s that the number of teams people can create is the maximum possible. 
Note that each participant can be in no more than one team.

You have to answer t independent test cases.
*/

