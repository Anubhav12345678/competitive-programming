#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int m,n,c[1000005];
ll ans[1000005]={0};
int main()
{
	cin>>m>>n;
	ans[0]=1;
	for(int i=1;i<=m;i++)
		cin>>c[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=c[i];j<=n;j++)
		{
			ans[j]+=ans[j-c[i]];
			ans[j]%=mod;
		}
	}
	//for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<ans[n]<<"\n";
	return 0;
}
/*
There is a hotel with M floors. ith floor of the hotel has infinite identical rooms, each room can accommodate c[i] people (Two 
rooms of same floor are indifferentiable and have same capacity while two rooms of different floors have different capacity).
There is one rule:
Any room on ith floor will accommodate exactly c[i] people (not less or more).

Now N identical people come for accommodation. You can assign any of them to any room of any floor following the mentioned rule.

Way of assigning:
If we have 5 people and 3 floors. Let's say floor 1 has room capacity 1 and floor 2 has room capacity 2, then:
(1,2,2) is a way of assigning people. This means we assign one person out of those 5 people to any room of floor 1.
 The remaining 4 people are assigned to two rooms of floor 2, each room accommodating 2 people.
We will consider (1,2,2), (2,1,2), (2,2,1) as the same ways as we can't differentiate between them.

You have to tell number of different ways of accommodating N people.
Two ways are considered different if one way is not a permutation of other way.

*/