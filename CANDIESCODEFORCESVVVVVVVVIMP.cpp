#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Recently Vova found n candy wrappers. He remembers that he bought x candies during the first day, 2x candies during the second day, 4x candies during the third day, …, 2k−1x candies during the k-th day. But there is an issue: Vova remembers neither x nor k but he is sure that x and k are positive integers and k>1.

Vova will be satisfied if you tell him any positive integer x so there is an integer k>1 that x+2x+4x+⋯+2k−1x=n. It is guaranteed that at least one solution exists. Note that k>1.

You have to answer t independent test cases.


*/
ll power[32];
void fill()
{
	memset(power,0LL,sizeof(power));
	power[0]=1LL;
	for(int i=1;i<=31;i++)
	{
	 power[i]=power[i-1]*2;
	 //cout<<"power["<<i<<"] = "<<power[i]<<" ";
	}
}
ll solve(ll n)
{
	for(int i=31;i>1;i--)
	{
		if(n%(power[i]-1)==0)
		{
		  ll k = n/(power[i]-1);
		  if(k>1&&n%k==0)
		  return k;
		}
	}
	return 1;
}
int main() {
	fill();
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
	// your code goes here
	return 0;
}