#include <bits/stdc++.h>
using namespace std;
#define ll long long
// generates prime in O(n*(log(logn)))
void primes(ll n)
{
	ll i,p;
	bool isprime[n+1];
	memset(isprime,true,sizeof(isprime));
	for(i=2;i*i<=n;i++)
	{
		for(p = i*i;p<=n;p+=i)
		{
			isprime[p] = false;
		}
	}
	for(i=2;i<=n;i++)
	if(isprime[i])
	cout<<i<<" ";
}
int main() {
	ll n;
	cin>>n;
	primes(n);
	// your code goes here
	return 0;
}
// another form
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200005
bool isprime[MAX+1];
void fill()
{
	ll primes[MAX+1];
	ll i,j;
	memset(isprime,true,sizeof(isprime));
	for(i=2;i*i<=MAX;i++)
	{
		for(j=i*2;j<=MAX;j+=i)
		isprime[j] = false;
	}
	for(i=2;i<=MAX;i++)
	if(isprime[i])
	{
		primes[i] = i;
		cout<<"primes["<<i<<"] = "<<primes[i]<<endl;
	}
}
int main() {
	fill();
	// your code goes here
	return 0;
}