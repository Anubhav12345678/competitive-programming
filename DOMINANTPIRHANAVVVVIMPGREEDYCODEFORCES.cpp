#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll a[],ll n)
{
	ll i,j,k,l,m=-1,v=-2;
	for(i=0;i<n;i++) m=max(m,a[i]);
	i=0;
	while(i<n&&v==-2)
	{
		if(m==a[i])
		{
			if(i>0&&m>a[i-1]) v=i;
			if(i<n-1&&m>a[i+1]) v=i;
		}
		i++;
	}
	return 1+v;
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
/*
There are n piranhas with sizes a1,a2,…,an in the aquarium. Piranhas are numbered from left to right in order they live in the aquarium.

Scientists of the Berland State University want to find if there is dominant piranha in the aquarium. The piranha is called dominant if it can eat all the other piranhas in the aquarium (except itself, of course). Other piranhas will do nothing while the dominant piranha will eat them.

Because the aquarium is pretty narrow and long, the piranha can eat only one of the adjacent piranhas during one move. Piranha can do as many moves as it needs (or as it can). More precisely:

The piranha i can eat the piranha i−1 if the piranha i−1 exists and ai−1<ai.
The piranha i can eat the piranha i+1 if the piranha i+1 exists and ai+1<ai.
When the piranha i eats some piranha, its size increases by one (ai becomes ai+1).

Your task is to find any dominant piranha in the aquarium or determine if there are no such piranhas.

Note that you have to find any (exactly one) dominant piranha, you don't have to find all of them.

For example, if a=[5,3,4,4,5], then the third piranha can be dominant. Consider the sequence of its moves:

The piranha eats the second piranha and a becomes [5,5–,4,5] (the underlined piranha is our candidate).
The piranha eats the third piranha and a becomes [5,6–,5].
The piranha eats the first piranha and a becomes [7–,5].
The piranha eats the second piranha and a becomes [8–].
You have to answer t independent test cases.


*/