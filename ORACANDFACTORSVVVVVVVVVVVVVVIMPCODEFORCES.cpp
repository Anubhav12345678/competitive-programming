#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*

Orac is studying number theory, and he is interested in the properties of divisors.

For two positive integers a and b, a is a divisor of b if and only if there exists an integer c, such that a⋅c=b.

For n≥2, we will denote as f(n) the smallest positive divisor of n, except 1.

For example, f(7)=7,f(10)=2,f(35)=5.

For the fixed integer n, Orac decided to add f(n) to n.

For example, if he had an integer n=5, the new value of n will be equal to 10. And if he had an integer n=6, n will be changed to 8.

Orac loved it so much, so he decided to repeat this operation several times.

Now, for two positive integers n and k, Orac asked you to add f(n) to n exactly k times (note that n will change after each operation, so f(n) may change too) and tell him the final value of n.

For example, if Orac gives you n=5 and k=2, at first you should add f(5)=5 to n=5, so your new value of n will be equal to n=10, after that, you should add f(10)=2 to 10, so your new (and the final!) value of n will be equal to 12.

Orac may ask you these queries many times.

*/
bool isprime[1000005];
void fill()
{
	ll i,j,k,l,n;
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=0;
	for(i=2;i*i<1000005;i++)
	{
		for(j=i*i;j<1000005;j+=i)
		isprime[j]=0;
	}
}
ll solve(ll n)
{
	ll i,j,k,l;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		break;
	}
	return i;
}
int main() {
	fill();
		ll t,i,j,k,l,n;
	cin>>t;
	// fill();
	while(t--)
	{
		cin>>n>>k;
		if(n%2==0)
		{
			cout<<n+k*2<<endl;
		}
		else
		{
			if(isprime[n])
			{
				ll ans = 2*n;
				k--;
				cout<<ans+k*2<<endl;
			}
			else
			{
				ll x = solve(n);
				k--;
				cout<<(n+x)+k*2<<endl;
			}
		}
		
	}
	// your code goes here
	return 0;
}