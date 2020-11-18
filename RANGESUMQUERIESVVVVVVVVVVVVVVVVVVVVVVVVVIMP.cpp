#include <bits/stdc++.h>
using namespace std;
/*
To stay woke and attentive during classes, Karen needs some coffee!


Karen, a coffee aficionado, wants to know the optimal temperature
 for brewing the perfect cup of coffee. Indeed, she has spent some
  time reading several recipe books, including the universally acclaimed "The Art of the Covfefe".

She knows n coffee recipes. The i-th recipe suggests that coffee 
should be brewed between li and ri degrees, inclusive, to achieve the optimal taste.

Karen thinks that a temperature is admissible if at least k recipes recommend it.

Karen has a rather fickle mind, and so she asks q questions. In each
 question, given that she only wants to prepare coffee with a temperature
  between a and b, inclusive, can you tell her how many admissible integer temperatures fall within the range?





*/
#define ll long long
#define MAX 200005
#include<vector>



vector<ll> v(MAX,0LL);
ll solve(ll l,ll r)
{
	return v[r]-v[l-1];
}

int main() {
	ll i,j,k,l,r,n,q,a,b,c;
	cin>>n>>k>>q;
	while(n--)
	{
		cin>>l>>r;
		v[l]++;
		v[r+1]--;
	}
	for(i=1;i<MAX;i++)
	v[i] = v[i]+v[i-1];
	for(i=1;i<MAX;i++)
	v[i] = (v[i]>=k)?1:0;
	for(i=1;i<MAX;i++)
	v[i]+=v[i-1];
	while(q--)
	{
		cin>>l>>r;
		cout<<solve(l,r)<<endl;
	}
	
	// your code goes here
	return 0;
}