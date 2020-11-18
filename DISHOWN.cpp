#include <iostream>
using namespace std;
#define ll long long
#define mx 1000005
ll N;
ll Parent[mx];
ll A[mx];
void initialise()
{
	ll i;
	for(i=0;i<=N;i++)
	Parent[i] = i;
}
ll find(ll a)
{
    if(Parent[a]==a)
    return a;
    return Parent[a] = find(Parent[a]);
    
}
bool compare(ll a,ll b)
{
	if(find(a)==find(b))
	{
		return false;
	}
	else
	{
	    ll x = find(a);
	    ll y = find(b);
		if(A[x]>A[y])
		Parent[y] = x;
		else if(A[x]<A[y])
		Parent[x] = y;
		return true;
	}
}
int main() {
	ll t,q,x,y,tt,i,j,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		N = n;
		initialise();
		for(i=1;i<=n;i++)
		cin>>A[i];
		cin>>q;
		while(q--)
		{
			cin>>tt;
			if(!tt)
			{
				cin>>x>>y;
				if(!compare(x,y))
				{
					cout<<"Invalid query!\n";
				}
			}
			else
			{
				cin>>x;
				cout<<find(x)<<endl;
			}
		}
	}
	// your code goes here
	return 0;
}