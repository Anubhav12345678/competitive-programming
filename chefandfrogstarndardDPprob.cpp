#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#define mx 1000005
struct animal
{
	ll ind;
	ll coordinate;
};
bool comparator(animal a,animal b)
{
	return (a.coordinate>b.coordinate);//arrange in dec oredr of their coordinates
}
void build(ll maxdis[],ll n,struct animal a[],ll k)
{
	ll i;
	sort(a,a+n,comparator);
	// for(i=0;i<n;i++)
	// cout<<a[i].coordinate<<" ";
	// cout<<endl;
	maxdis[a[0].ind] = a[0].coordinate+k;//last one can communicate to a dis of its coordinate+k
	for(i=1;i<n;i++)
	{
		if((a[i-1].coordinate-a[i].coordinate)<=k)
		{
			maxdis[a[i].ind] = maxdis[a[i-1].ind];
		}
		else
		{
			maxdis[a[i].ind] = a[i].coordinate+k;
		}
		
	}
	// for(i=0;i<n;i++)
	// {
	// 	cout<<a[i].ind<<" "<<maxdis[a[i].ind]<<endl;
	// }
}
int main() {
	// memset(maxdis,0,sizeof(maxdis));
	struct animal a[100005];
	ll i,j,k,p,n,h,b;
	cin>>n>>k>>p;
	ll maxdis[n];
	memset(maxdis,0,sizeof(maxdis));
	for(i=0;i<n;i++)
	{
		cin>>a[i].coordinate;
		a[i].ind = i;
	}
	build(maxdis,n,a,k);
	while(p--)
	{
		cin>>h>>b;
		if(maxdis[h-1]==maxdis[b-1])
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	
	// your code goes here
	return 0;
}