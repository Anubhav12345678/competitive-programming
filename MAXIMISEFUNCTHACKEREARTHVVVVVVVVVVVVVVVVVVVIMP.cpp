#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
/*

You are given an array  (indexed  through ) and an integer .

Given:                 

 for some integer . You have to find the maximum possible value of   such that  is greater than or equal to .
 https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/not-decided/description/

*/
ll solveutil(ll m,vector<ll> &v)
{
	ll ans=0LL;
	ll n = v.size();
	for(ll i=0;i<n;i++)
	{
		ans+=max(0LL,v[i]-m*(i+1));
	}
	return ans;
}
ll solve(vector<ll> &v,ll k)
{
  ll t,i,j,l,n=v.size(),y,x,a,b,c;
  
	 
	ll L = 0, R = 1e12;
	ll ans=-1;
	while(L<=R)
	{
		ll m = L+(R-L)/2;
		if(solveutil(m,v)<k)
		R = m-1;
		else
		{
			if(solveutil(m+1,v)<k) return m;
			else
			L=m+1;
		}
		
	}
	return ans;
} 
int main()
{
   ll i,j,k,l,n,t;
   cin>>t;
   while(t--)
   {
	   cin>>n>>k;
	   vector<ll> v(n);
	   for(i=0;i<n;i++) cin>>v[i];
	   ll y = solve(v,k);
	   ll s=solveutil(y,v);
	   cout<<y<<" "<<s<<endl;
	   
   }
   return 0;
}










