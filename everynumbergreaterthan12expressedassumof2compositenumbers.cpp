#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isprime[1000005];
void fill()
{
	memset(isprime,true,sizeof(isprime));
	ll i,j,k,l;
	isprime[0]=false;
	isprime[1]=false;
	for(i=2;i*i<1000005;i++)
	{
		for(j=i*i;j<1000005;j+=i)
		isprime[j]=false;
	}
}
int main() {
	fill();
	ll n,x,y;
	cin>>n;
	for(ll i=2;i<=n/2;i++)
	{
		if(!isprime[i]&&!isprime[n-i])
		{
			cout<<i<<" "<<n-i<<endl;
			return 0;
		}
	}
	// your code goes here
	return 0;
}