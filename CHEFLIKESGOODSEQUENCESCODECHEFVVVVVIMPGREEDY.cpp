#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		ll q;
		cin>>n>>q;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		ll ans=1;
		for(i=1;i<n;i++)
		if(a[i]!=a[i-1]) ans++;
		while(q--)
		{
			ll x,y;
			cin>>x>>y;
			x--;
			if(a[x]!=y)
			{
				if(x+1<n)
				{
					if(a[x+1]==y&&a[x]!=a[x+1]) ans--;
					else if(a[x+1]!=y&&a[x]==a[x+1]) ans++;
				}
				if(x-1>=0)
				{
					if(a[x-1]==y&&a[x]!=a[x-1]) ans--;
					else if(a[x-1]!=y&&a[x]==a[x-1]) ans++;
				}
			}
			a[x]=y;
			cout<<ans<<endl;
		}
	}
	// your code goes here
	return 0;
}

/*
Chef calls a sequence good if it does not contain any two adjacent identical elements.

Initially, Chef has a sequence a1,a2,…,aN. He likes to change the sequence every now and then. You should process Q queries. In each query, Chef chooses an index x and changes the x-th element of the sequence to y. After each query, can you find the length of the longest good subsequence of the current sequence?

Note that the queries are not independent.


*/