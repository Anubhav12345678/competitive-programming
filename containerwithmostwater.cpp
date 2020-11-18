#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<iterator>
#define pb push_back
#define f first
#define s second
#define VI vector<pair<ll, ll>>
#define mp make_pair
#include<math.h>
int main() {
	ll n,t,i,j,k,a[10001],best,temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		i=0;
		j=n-1;
		best=0;
		while(i!=j)
		{
			temp = (j-i)*min(a[i],a[j]);//area is calculated this way
			if(temp>best)
			best = temp;
			if(a[j]>a[i])
			i++;
			else
			j--;
		}
		cout<<best<<endl;
	}
	// your code goes here
	return 0;
}