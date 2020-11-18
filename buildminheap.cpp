#include <bits/stdc++.h>
using namespace std;
#define ll long long
void minheapify(ll a[],ll n,ll i)
{
	ll temp;
	ll smallest = i;
	ll l = 2*i+1;
	ll r = 2*i+2;
	if(l<n&&a[smallest]>a[l])
	smallest=l;
	if(r<n&&a[smallest]>a[r])
	smallest = r;
	if(smallest!=i)
	{
		temp = a[smallest];
		a[smallest] = a[i];
		a[i] = temp;
		minheapify(a,n,smallest);
	}
}
void buildminheap(ll a[],ll n)
{
	ll i;
	for(i=n/2;i>=0;i--)
	{
		minheapify(a,n,i);
	}
	
}
int main() {
	ll n,a[100005],i,j,k,t;
	cin>>n>>k;
	ll b[n];
	t=n;
	for(i=0;i<n;i++)
	{
	cin>>a[i];
	b[i] = a[i];
	}
	buildminheap(a,n);
	ll s=0;
	// for(i=0;i<n;i++)
	// cout<<a[i]<<" ";
	while(k--&&n>=0)
	{
		ll x = a[0];
		cout<<"x = "<<x<<endl;
		a[0] = a[n-1];
		a[n-1] = x;
		n--;
		minheapify(a,n,0);
		if(a[0]==0)
		break;
		x=(-1)*x;
        s+=x;
        cout<<s<<endl;
	}
	for(i=0;i<t;i++)
	if(a[i]>0)
	s+=a[i];
	cout<<s<<endl;
	// your code goes here
	return 0;
}