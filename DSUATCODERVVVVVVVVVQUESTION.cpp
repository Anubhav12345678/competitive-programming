#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<map>
#define ff first
#define se second
#define N 200005
vector<ll> par(N);
vector<ll> c(N);
vector<ll> sz(N);
map<ll,ll> mp[N];
ll find(ll x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

void merge(ll a,ll b)
{
	ll x = find(a);
	ll y = find(b);
	if(x==y) return;
	if(sz[x]>=sz[y])
	swap(x,y);
	sz[y]+=sz[x];
	par[x]=y;
	for(auto it: mp[x])
	mp[y][it.ff]+= it.se;
}

void init(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		par[i]=i;
		sz[i]=1;
		mp[i][c[i]]=1;
	}
}
int main() {
	
	ll n,q,i,j,k,l;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	init(n);
	while(q--)
	{
		ll type,x,y;
		cin>>type>>x>>y;
		if(type==1)
		merge(x,y);
		else
		{
			if(mp[find(x)].count(y)>0)
			cout<<mp[find(x)][y]<<endl;
			else
			cout<<"0\n";
		}
	}
	
	
	// your code goes here
	return 0;
}
/*
N
 students are about to go to school. Student 
i
 belongs to Class 
C
i
.

After leaving home, each student will head to school while repeatedly joining up with a group of other students. Once students join up with each other, they will not separate.

You will be given 
Q
 queries that should be processed in order. There are two kinds of queries, in the following formats, that mean the following:

1 a b: The group containing Student 
a
 and the group containing Student 
b
 merges. (If they are already in the same group, nothing happens.)
2 x y: You are asked to find the number of students belonging to Class 
y
 who are already in the same group as Student 
x
 (including Student 
x
) at the time of this query.



*/