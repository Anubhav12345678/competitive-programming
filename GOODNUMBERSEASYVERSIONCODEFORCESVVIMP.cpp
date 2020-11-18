#include <bits/stdc++.h>
using namespace std;
#define ll long long
//easy version n<=10^4
bool isgood(ll n)
{
	while(n)
	{
		if(n%3==2)
		return false;
		n=n/3;
	}
	return true;
}
int main() {
	ll q,n,i,j,k,l;
	cin>>q;
	while(q--)
	{
		cin>>n;
		while(!isgood(n))
		{
			n++;
		}
		cout<<n<<endl;
	}
	// your code goes here
	return 0;
}

//hard verion n<=10^18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n)
{
	ll sum=0,tmp=1;
	while(sum<n)
	{
		sum+=tmp;
		tmp*=3;
	}
	while(tmp)
	{
		if(sum-tmp>=n)sum-=tmp;
		tmp/=3;
	}
	return sum;
}
int main() {
	ll n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
	// your code goes here
	return 0;
}