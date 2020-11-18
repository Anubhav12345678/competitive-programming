#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
/*
You have n students under your control and you have to compose exactly two teams consisting of some subset
 of your students. Each student had his own skill, the i-th student skill is denoted by an integer ai (different
  students can have the same skills).

So, about the teams. Firstly, these two teams should have the same size. Two more constraints:

The first team should consist of students with distinct skills (i.e. all skills in the first team are unique).
The second team should consist of students with the same skills (i.e. all skills in the second team are equal).
Note that it is permissible that some student of the first team has the same skill as a student of the second team.

Consider some examples (skills are given):

[1,2,3], [4,4] is not a good pair of teams because sizes should be the same;
[1,1,2], [3,3,3] is not a good pair of teams because the first team should not contain students with the same skills;
[1,2,3], [3,4,4] is not a good pair of teams because the second team should contain students with the same skills;
[1,2,3], [3,3,3] is a good pair of teams;
[5], [6] is a good pair of teams.
Your task is to find the maximum possible size x for which it is possible to compose a valid pair of teams, where each team
 size is x (skills in the first team needed to be unique, skills in the second team should be the same between them). 
 A student cannot be part of more than one team.

You have to answer t independent test cases.

*/
ll solve(ll a[],ll n)
{
	ll i,j,k,l;
	if(n==1) return 0;
	map<ll,ll> mp;
	ll mf=0;
	for(i=0;i<n;i++)
	{
		mp[a[i]]++;
		mf = max(mf,mp[a[i]]);
	}
	if(mf==1)
	return 1;
	ll dis = mp.size();
	return max(min(dis-1,mf),min(dis,mf-1));
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		cout<<solve(a,n)<<endl;
	}
	// your code goes here
	return 0;
}